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
#include "ftellBuiltin.hpp"
#include "Error.hpp"
#include "File.hpp"
#include "FileTell.hpp"
#include "FilesManager.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::StreamGateway::ftellBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(argIn, 1, 1);
    nargoutcheck(nLhs, 0, 1);
    ArrayOf param1 = argIn[0];
    auto iValue = static_cast<int32>(param1.getContentAsDoubleScalar());
    auto* fm = static_cast<FilesManager*>(eval->FileManager);
    if (fm == nullptr) {
        Error(_W("Problem with file manager."));
    }
    if (fm->isOpened(iValue)) {
        File* f = fm->getFile(iValue);
        if (f == nullptr) {
            Error(_W("Invalid file identifier."));
        }
        auto dpos = static_cast<double>(FileTell(f));
        retval << ArrayOf::doubleConstructor(dpos);
    } else {
        Error(_W("Invalid file identifier."));
    }
    return retval;
}
//=============================================================================
