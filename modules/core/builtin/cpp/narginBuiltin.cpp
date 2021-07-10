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
#include "narginBuiltin.hpp"
#include "Error.hpp"
#include "NargIn.hpp"
#include "characters_encoding.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::CoreGateway::narginBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 1);
    nargincheck(argIn, 0, 1);
    if (argIn.empty()) {
        Context* context = eval->getContext();
        if (context->getCurrentScope()->getName() == "base") {
            Error(_W("not allowed in base scope."));
        } else {
            int nargin = context->getCurrentScope()->getNargIn();
            retval << ArrayOf::doubleConstructor(nargin);
        }
    } else // argIn.size() == 1
    {
        ArrayOf param1 = argIn[0];
        std::wstring name;
        if (param1.isRowVectorCharacterArray()) {
            name = param1.getContentAsWideString();
        } else if (param1.isFunctionHandle()) {
            function_handle fh = param1.getContentAsFunctionHandle();
            auto* funcDef = (FunctionDef*)fh;
            if (eval->getContext()->getGlobalScope()->isPointerOnFunction(funcDef)) {
                name = utf8_to_wstring(funcDef->getName());
            } else {
                Error(ERROR_WRONG_ARGUMENT_1_TYPE_FUNCTION_HANDLE_EXPECTED);
            }
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_OR_FUNCTION_HANDLE_EXPECTED);
        }
        retval << ArrayOf::doubleConstructor(NargIn(eval, name));
    }
    return retval;
}
//=============================================================================
