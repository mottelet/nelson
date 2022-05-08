//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "backgroundPoolBuiltin.hpp"
#include "Error.hpp"
#include "BackgroundPoolObject.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::ParallelGateway::backgroundPoolBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargincheck(nLhs, 0, 0);
    nargoutcheck(nLhs, 0, 1);
    BackgroundPoolObject* backgroundPoolObject = new BackgroundPoolObject();
    retval << ArrayOf::handleConstructor(backgroundPoolObject);
    return retval;
}
//=============================================================================
