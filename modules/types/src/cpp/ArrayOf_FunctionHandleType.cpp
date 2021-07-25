//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "ArrayOf.hpp"
#include "Error.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
bool
ArrayOf::isFunctionHandle() const
{
    if (this->isClassStruct()) {
        std::string classString = this->getStructType();
        return (classString == NLS_FUNCTION_HANDLE_STR);
    }
    return false;
}
//=============================================================================
function_handle
ArrayOf::getContentAsFunctionHandle()
{
    function_handle fh;
    std::string classString = this->getStructType();
    if (classString == NLS_FUNCTION_HANDLE_STR) {
        ArrayOf nameField = this->getField("name");
        ArrayOf anonymousField = this->getField("anonymous");
        ArrayOf argumentsField = this->getField("arguments");
        ArrayOf codeField = this->getField("code");
        fh.name = nameField.getContentAsCString();
        fh.anonymous = anonymousField.getContentAsCString();
        fh.arguments = argumentsField.getContentAsCStringVector();

        indexType codeLength = codeField.getElementCount();
        char* ptr = (char*)codeField.getDataPointer();
        std::vector<char> serializedCode;
        serializedCode.reserve(codeLength);
        for (size_t k = 0; k < codeLength; ++k) {
            serializedCode.push_back(ptr[k]);
        }
        fh.expressionSerialized = serializedCode;
    } else {
        Error(_W("Expected a function_handle."));
    }
    return fh;
}
//============= ================================================================
ArrayOf
ArrayOf::functionHandleConstructor(const std::wstring& functionName, const std::wstring& anonymous)
{
    function_handle fptr;

    fptr.name = wstring_to_utf8(functionName);
    fptr.anonymous.clear();
    fptr.arguments.clear();
    fptr.expressionSerialized.clear();
    return functionHandleConstructor(fptr);
}
//=============================================================================
ArrayOf
ArrayOf::functionHandleConstructor(function_handle fptr)
{
    ArrayOf structArray = ArrayOf::emptyConstructor(0, 0);
    structArray.setField("name", ArrayOf::characterArrayConstructor(fptr.name));
    structArray.setField("anonymous", ArrayOf::characterArrayConstructor(fptr.anonymous));

    Dimensions dimsArguments(1, fptr.arguments.size());
    ArrayOf* elements = (ArrayOf*)ArrayOf::allocateArrayOf(NLS_CELL_ARRAY, fptr.arguments.size());
    ArrayOf arguments = ArrayOf(NLS_CELL_ARRAY, dimsArguments, elements);

    for (size_t k = 0; k < fptr.arguments.size(); ++k) {
        elements[k] = ArrayOf::characterArrayConstructor(fptr.arguments[k]);
    }
    structArray.setField("arguments", arguments);
 
    Dimensions dimsCode(1, fptr.expressionSerialized.size());
    int8* ptr = (int8*)ArrayOf::allocateArrayOf(NLS_INT8, fptr.expressionSerialized.size());
    memcpy(ptr, fptr.expressionSerialized.data(), fptr.expressionSerialized.size() * sizeof(char));
    ArrayOf code = ArrayOf(NLS_INT8, dimsCode, ptr);

    structArray.setField("code", code);

    structArray.setStructType(NLS_FUNCTION_HANDLE_STR);
    return structArray;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
