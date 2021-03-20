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
#include <sciplot/sciplot.hpp>
#include "Figure.hpp"
#include "HandleGenericObject.hpp"
#include "HandleManager.hpp"
#include "GFigureObject.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
Figure()
{
    
    sciplot::Plot plot;
    std::vector<std::vector<sciplot::PlotXD>> plots = { { plot } };
    sciplot::Figure* ptrFigure = new sciplot::Figure(plots);
    HandleGenericObject* hl = new GFigureObject(ptrFigure);
    HandleManager::getInstance()->addHandle(hl);
    return ArrayOf::handleConstructor(hl);
}
//=============================================================================
std::wstring
displayFigureInformation(void* ptrHandle)
{
    std::wstring res;
    if (ptrHandle) {
        HandleGenericObject* hl = (HandleGenericObject*)ptrHandle;
        sciplot::Figure* ptrFigure = (sciplot::Figure*)(hl->getPointer());
    }
    return res;
}
//=============================================================================
void
showFigure(void* ptrHandle)
{
    if (ptrHandle) {
        HandleGenericObject* hl = (HandleGenericObject*)ptrHandle;
        sciplot::Figure* ptrFigure = (sciplot::Figure*)(hl->getPointer());
        ptrFigure->show();
    }
}
//=============================================================================
}
//=============================================================================
