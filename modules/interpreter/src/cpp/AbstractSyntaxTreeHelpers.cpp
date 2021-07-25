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
#include "AbstractSyntaxTree.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static std::string
expression(AbstractSyntaxTreePtr expr)
{
    if (expr == nullptr) {
        return "";
    }
    std::string res;
    switch (expr->type) {
    case id_node: {
        res = expr->text + expression(expr->down);
    } break;
    case const_character_array_node: {
        res = "'" + expr->text + "'";
    } break;
    case const_string_node: {
        res = "\"" + expr->text + "\"";
    } break;
    case const_int_node:
    case const_uint64_node:
    case const_float_node:
    case const_double_node: {
        res = expr->text;
    } break;
    case const_complex_node:
    case const_dcomplex_node: {
        res = expr->text + "i";
    } break;
    case reserved_node: {
        res = expr->text;
    } break;
    default: {
        switch (expr->opNum) {
        case OP_COLON: {
            if ((expr->down != nullptr) && (expr->down->opNum == (OP_COLON))) {
                res = expression(expr->down->down) + ":" + expression(expr->down->down->right) + ":"
                    + expression(expr->down->right);
            } else {
                res = expression(expr->down) + ":" + expression(expr->down->right);
            }
        } break;
        case OP_SEMICOLON: {
            if (expr->right != nullptr) {
                res = expression(expr->down) + ";" + expression(expr->right);
            } else {
                res = expression(expr->down) + "," + expression(expr->down->right);
            }
        } break;
        case OP_EMPTY: {
            res = "[]";
        } break;
        case OP_EMPTY_CELL: {
            res = "{}";
        } break;
        case OP_BRACKETS: {
            res = "[" + expression(expr->down) + "]";
        } break;
        case OP_BRACES: {
            res = "{" + expression(expr->down) + "}";
        } break;
        case OP_PARENS: {
            res = "(" + expression(expr->down) + ")";
        } break;
        case OP_PLUS: {
            res = expression(expr->down) + "+" + expression(expr->down->right);
        } break;
        case OP_SUBTRACT: {
            res = expression(expr->down) + "-" + expression(expr->down->right);
        } break;
        case OP_TIMES: {
            res = expression(expr->down) + "*" + expression(expr->down->right);
        } break;
        case OP_SOR: {
            res = expression(expr->down) + "||" + expression(expr->down->right);
        } break;
        case OP_OR: {
            res = expression(expr->down) + "|" + expression(expr->down->right);
        } break;
        case OP_SAND: {
            res = expression(expr->down) + "&&" + expression(expr->down->right);
        } break;
        case OP_AND: {
            res = expression(expr->down) + "&" + expression(expr->down->right);
        } break;
        case OP_LT: {
            res = expression(expr->down) + "<" + expression(expr->down->right);
        } break;
        case OP_LEQ: {
            res = expression(expr->down) + "<=" + expression(expr->down->right);
        } break;
        case OP_GT: {
            res = expression(expr->down) + ">" + expression(expr->down->right);
        } break;
        case OP_GEQ: {
            res = expression(expr->down) + ">=" + expression(expr->down->right);
        } break;
        case OP_EQ: {
            res = expression(expr->down) + "==" + expression(expr->down->right);
        } break;
        case OP_NEQ: {
            res = expression(expr->down) + "~=" + expression(expr->down->right);
        } break;
        case OP_DOT_TIMES: {
            res = expression(expr->down) + ".*" + expression(expr->down->right);
        } break;
        case OP_POS: {
            res = "+" + expression(expr->down);
        } break;
        case OP_NEG: {
            res = "-" + expression(expr->down);
        } break;
        case OP_NOT: {
            res = "~" + expression(expr->down);
        } break;
        case OP_TRANSPOSE: {
            res = expression(expr->down) + "'";
        } break;
        case OP_DOT_TRANSPOSE: {
            res = expression(expr->down) + ".'";
        } break;
        case OP_RHS: {
            res = expression(expr->down);
        } break;
        case OP_RDIV: {
            res = expression(expr->down) + "/" + expression(expr->down->right);
        } break;
        case OP_LDIV: {
            res = expression(expr->down) + "\\" + expression(expr->down->right);
        } break;
        case OP_DOT_RDIV: {
            res = expression(expr->down) + "./" + expression(expr->down->right);
        } break;
        case OP_DOT_LDIV: {
            res = expression(expr->down) + ".\\" + expression(expr->down->right);
        } break;
        case OP_POWER: {
            res = expression(expr->down) + "^" + expression(expr->down->right);
        } break;
        case OP_DOT_POWER: {
            res = expression(expr->down) + ".^" + expression(expr->down->right);
        } break;
        case OP_FUNCTION_HANDLE_ANONYMOUS: {
            res = "@" + expression(expr->down);
        } break;
        case OP_FUNCTION_HANDLE_NAMED: {
            res = "@" + expression(expr->down);
        } break;
        default: {
        } break;
        }
    } break;
    }

    return res;
}
//=============================================================================
std::string
AbstractSyntaxTree::toString(AbstractSyntaxTreePtr expr)
{
    std::string res = expression(expr);
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
