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
#include "AnonymousFunctionName.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
std::string
AnonymousFunctionName(function_handle afh)
{
    std::string name;
    if (!afh.anonymous.empty()) {
        if (afh.anonymous[0] != '@') {
            std::string arguments;
            for (size_t k = 0; k < afh.arguments.size(); ++k) {
                if (k == 0) {
                    arguments = afh.arguments[k];
                } else {
                    arguments = arguments + "," + afh.arguments[k];
                }
            }
            name = "@(" + arguments + ")" + afh.anonymous;
        } else {
            name = afh.anonymous;
        }
    }
    return name;
}
//=============================================================================
}
//=============================================================================
