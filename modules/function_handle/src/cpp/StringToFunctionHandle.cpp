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
#include <boost/algorithm/string.hpp>
#include "StringToFunctionHandle.hpp"
#include "characters_encoding.hpp"
#include "IsValidVariableName.hpp"
#include "ParserInterface.hpp"
#include "AbstractSyntaxTree.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
function_handle
StringToFunctionHandle(const std::wstring& anonymousFunctionOrFunctionName)
{
    function_handle functionHandle;
    std::wstring _anonymousFunctionOrFunctionName
        = boost::algorithm::trim_left_copy(anonymousFunctionOrFunctionName);
    boost::algorithm::trim_right(_anonymousFunctionOrFunctionName);
    if (!_anonymousFunctionOrFunctionName.empty() && _anonymousFunctionOrFunctionName[0] == L'@') {
        _anonymousFunctionOrFunctionName = _anonymousFunctionOrFunctionName.substr(
            1, _anonymousFunctionOrFunctionName.length());
        boost::algorithm::trim_left(_anonymousFunctionOrFunctionName);
        _anonymousFunctionOrFunctionName = L"@" + _anonymousFunctionOrFunctionName;
        ParserState parserState = ParseError;
        parserState = parseString(wstring_to_utf8(_anonymousFunctionOrFunctionName) + "\n");
        if (parserState == ScriptBlock) {
            AbstractSyntaxTreePtr tree = getParsedScriptBlock();
            AbstractSyntaxTreePtr t = tree->down->down;
            if (t->opNum == OP_FUNCTION_HANDLE_ANONYMOUS) {
                stringVector arguments = t->down->toStringList();
                AbstractSyntaxTreePtr code = t->down->right;
                AbstractSyntaxTree::serialize(code, functionHandle.expressionSerialized);
                functionHandle.anonymous = wstring_to_utf8(_anonymousFunctionOrFunctionName);
                functionHandle.arguments = arguments;

            } else {
                Error(_W("valid anonymous function handle expected."));
            }
        }
    } else {
        if (IsValidVariableName(_anonymousFunctionOrFunctionName)) {
            functionHandle.name = wstring_to_utf8(_anonymousFunctionOrFunctionName);
            functionHandle.anonymous.clear();
        }
    }

    /*
    if (IsValidVariableName(functionName)) {
        functionHandle.name = wstring_to_utf8(functionName);
        functionHandle.anonymous.clear();
    } else {
        functionHandle.name.clear();
        ParserState parserState = ParseError;
        parserState = parseString(wstring_to_utf8(functionName) + "\n");
        if (parserState == ScriptBlock) {
            AbstractSyntaxTreePtr tree = getParsedScriptBlock();
            functionHandle.arguments = tree->toStringList();
            functionHandle.anonymous = wstring_to_utf8(functionName);
            AbstractSyntaxTree::serialize(tree, functionHandle.expressionSerialized);
        }
    }
    */
    return functionHandle;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
