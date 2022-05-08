//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include <vector>
#include <thread_pool.hpp>
#include "nlsParallel_exports.h"
#include "HandleGenericObject.hpp"
#include "Types.hpp"
#include "ArrayOf.hpp"
#include "Interface.hpp"
#include "FevalFutureObject.hpp"
#include "FunctionDef.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
#define BACKGROUNDPOOL_CATEGORY_STR L"backgroundPool"
//=============================================================================
class NLSPARALLEL_IMPEXP BackgroundPoolObject : public HandleGenericObject
{
public:
    BackgroundPoolObject();
    ~BackgroundPoolObject() override;

    void
    display(Interface* io);

    FevalFutureObject *
    feval(FunctionDef* fptr, int nLhs, const ArrayOfVector& argIn);

private:
    std::vector<FevalFutureObject*> fEvalQueue;
    wstringVector propertiesNames;
    thread_pool threadPool;

};
//=============================================================================
} // namespace Nelson
//=============================================================================
