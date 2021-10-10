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
#include "moreBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
// more('on')
// more('off')
// more(5)
// old = more('on')
// old = more('off')
// old = more(5)
// more('default')
// [status, n] = more()
//=============================================================================
ArrayOfVector
Nelson::CoreGateway::moreBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 0, 1);
    Interface* io = eval->getInterface();
    if (io == nullptr || !io->moreSupported())
    {
        Error(_W("'more' function not supported in this interface mode."), L"Nelson:more:functionNotSupported.");
    }
    switch (argIn.size()) {
    case 0: {
        nargoutcheck(nLhs, 0, 2);
    } break;
    case 1: {
        nargoutcheck(nLhs, 0, 1);
    }
    default: {
      // never
    } break;
    }
    
    return retval;
}
//=============================================================================
