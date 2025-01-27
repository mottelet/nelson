//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "GOScalarDoubleProperty.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void
GOScalarProperty::data(double x)
{
    at(0) = x;
}
//=============================================================================
double
GOScalarProperty::data()
{
    return at(0);
}
//=============================================================================
std::wstring
GOScalarProperty::toWideString()
{
    double value = at(0);
    std::wstring msg;
    if (std::fabs((double)(int)(value)-value) < std::numeric_limits<double>::epsilon()) {
        msg = std::to_wstring((int)value);
    } else {
        msg = std::to_wstring(value);
    }
    return msg;
}
//=============================================================================
}
