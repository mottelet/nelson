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
#include "Evaluator.hpp"
#include "NelsonGateway.hpp"
#include "createPlotObjectBuiltin.hpp"
#include "gplot_dispBuiltin.hpp"
#include "gplot_showBuiltin.hpp"
#include "gplot_drawCurveBuiltin.hpp"
#include "createFigureObjectBuiltin.hpp"
#include "gfigure_dispBuiltin.hpp"
#include "gfigure_showBuiltin.hpp"

//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"gnuplot";
//=============================================================================
static const nlsGateway gateway[] = {
    { "createPlot", (void*)Nelson::GnuplotGateway::createPlotObjectBuiltin, -1, -3, CPP_BUILTIN },
    { "gplot_disp", (void*)Nelson::GnuplotGateway::gplot_dispBuiltin, 0, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "gplot_show", (void*)Nelson::GnuplotGateway::gplot_showBuiltin, 0, 1, CPP_BUILTIN },
    { "gplot_drawCurve", (void*)Nelson::GnuplotGateway::gplot_drawCurveBuiltin, 0, 3, CPP_BUILTIN },

    { "createFigure", (void*)Nelson::GnuplotGateway::createFigureObjectBuiltin, -1, -3, CPP_BUILTIN },
    { "gfigure_disp", (void*)Nelson::GnuplotGateway::gfigure_dispBuiltin, 0, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "gfigure_show", (void*)Nelson::GnuplotGateway::gfigure_showBuiltin, 0, 1, CPP_BUILTIN },

};
//=============================================================================
NLSGATEWAYFUNC(gateway)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVE(gateway)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
