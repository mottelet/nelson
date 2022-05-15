//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "questdlgBuiltin.hpp"
#include "Error.hpp"
#include "QuestionBox.hpp"
#include "IsCellOfStrings.hpp"
#include "Warning.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::GuiGateway::questdlgBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    // s = questdlg(quest)
    // s = questdlg(quest, dlgtitle)
    // s = questdlg(quest, dlgtitle, btn1, btn2, activeBtn) 
    // s = questdlg(quest, dlgtitle, btn1, btn2, btn3, activeBtn)
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 1);
    nargincheck(argIn, 1, 6);
    std::wstring title;
    std::wstring defaultButton;
    std::wstring button1;
    std::wstring button2;
    std::wstring button3;
    bool needsLookup = false;
    int numButtons;

    if (argIn.size() == 1) {
        title = L" ";
    }
    if (argIn.size() <= 2) {
        defaultButton = L"Yes";
        needsLookup = true;
    }

    if (argIn.size() == 3) {
        defaultButton = button1;
    }
    if (argIn.size() <= 3) {
        button1 = L"Yes";
        button2 = L"No";
        button3 = L"Cancel";
        numButtons = 3;
        needsLookup = true;

    }
    if (argIn.size() == 4) {
        defaultButton = button2;
        button2.clear();
        button3.clear();
        numButtons = 1;
    }
    if (argIn.size() == 5) {
        defaultButton = button3;
        button3.clear();
        numButtons = 2;
    }
    if (argIn.size() == 6) {
        numButtons = 3;
    }

    return retval;
}
//=============================================================================
