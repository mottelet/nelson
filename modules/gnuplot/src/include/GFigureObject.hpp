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
#pragma once
//=============================================================================
#include "nlsGnuplot_exports.h"
#include "ArrayOf.hpp"
#include "HandleGenericObject.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
#define GFIGURE_CATEGORY_STR L"gfigure"
//=============================================================================
class NLSGNUPLOT_IMPEXP GFigureObject : public HandleGenericObject
{
public:
    //=============================================================================
    GFigureObject(void* ptr) : HandleGenericObject(GFIGURE_CATEGORY_STR, ptr, false) {};
    //=============================================================================
    int
    methodLhs(const std::wstring& methodName)
    {
        if (methodName == L"show") {
            return 0;
        }
        if (methodName == L"disp") {
            return 0;
        }
        return -1;
    }
    //=============================================================================
    bool
    isMethod(const std::wstring& methodName)
    {
        if (methodName == L"drawCurve") {
            return true;
        }
        return false;
    };
    //=============================================================================
};
//=============================================================================
} // namespace Nelson
//=============================================================================
