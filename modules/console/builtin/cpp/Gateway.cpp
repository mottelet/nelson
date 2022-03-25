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
#include "NelsonGateway.hpp"
#include "clcBuiltin.hpp"
#include "inputBuiltin.hpp"
#include "terminal_sizeBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"console";
//=============================================================================
static const nlsGateway gateway[] = {
    { "clc", (ptrBuiltin)Nelson::ConsoleGateway::clcBuiltin, 0, 0, CPP_BUILTIN_WITH_EVALUATOR },
    { "input", (ptrBuiltin)Nelson::ConsoleGateway::inputBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "terminal_size", (ptrBuiltin)Nelson::ConsoleGateway::terminal_sizeBuiltin, 1, 0, CPP_BUILTIN_WITH_EVALUATOR }

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
