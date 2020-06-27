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
#include "nlsMex_exports.h"
#include "mex.h"
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    //=============================================================================
    NLSMEX_IMPEXP
    bool
    mxIsLogical(const mxArray* pm);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateLogicalScalar(mxLogical value);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateLogicalMatrix(mwSize m, mwSize n);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateLogicalArray(mwSize ndim, const mwSize* dims);
    //=============================================================================
    NLSMEX_IMPEXP
    mxLogical*
    mxGetLogicals(const mxArray* array_ptr);
    //=============================================================================
    NLSMEX_IMPEXP
    bool
    mxIsLogicalScalar(const mxArray* array_ptr);
    //=============================================================================
    NLSMEX_IMPEXP
    bool
    mxIsLogicalScalarTrue(const mxArray* array_ptr);
    //=============================================================================
#ifdef __cplusplus
}
#endif
//=============================================================================
