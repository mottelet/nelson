//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "whosnh5Builtin.hpp"
#include "whosNh5File.hpp"
#include "CheckerHelpers.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOfVector
Nelson::Hdf5Gateway::whosnh5Builtin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 1);
    nargincheck(argIn, 1);
    std::wstring filename = argIn[0].getContentAsWideString();
    wstringVector names;
    for (indexType k = 1; k < (indexType)argIn.size(); k++) {
        names.push_back(argIn[k].getContentAsWideString());
    }
    Interface* io = eval->getInterface();
    ArrayOf st = whosNh5File(io, filename, names, nLhs == 1);
    if (nLhs == 1) {
        retval << st;
    }
    return retval;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
