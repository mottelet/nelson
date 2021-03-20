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
#include "gplot_drawCurveBuiltin.hpp"
#include "Plot.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::GnuplotGateway::gplot_drawCurveBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 3, 3);
    nargoutcheck(nLhs, 0, 1);
    ArrayOf arg = argIn[0];
    ArrayOf X = argIn[1];
    ArrayOf Y = argIn[2];

    if (!arg.isHandle()) {
        Error(_W("gplot handle expected."));
    }
    if (arg.getHandleCategory() != GPLOT_CATEGORY_STR) {
        Error(_W("gplot handle expected."));
    }

    if (!X.isNumeric()) {
        Error(_W("#1 numeric value expected."));
    }
    if (!Y.isNumeric()) {
        Error(_W("#2 numeric value expected."));
    }

    X.promoteType(NLS_DOUBLE);
    Y.promoteType(NLS_DOUBLE);

    Dimensions dimsX = X.getDimensions();
    Dimensions dimsY = Y.getDimensions();
    if (!dimsX.equals(dimsY)) {
        Error(_W("same size expected."));
    }
    if (!dimsX.isVector()) {
        Error(_W("Vector expected."));
    }

    if (arg.isScalar()) {
        drawCurve(arg.getContentAsHandleScalar(), (double*)X.getDataPointer(),
            (double*)Y.getDataPointer(),
            X.getElementCount());
    }
    return retval;
}
//=============================================================================
