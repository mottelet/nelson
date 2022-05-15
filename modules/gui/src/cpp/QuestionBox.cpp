//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <QtWidgets/QMessageBox>
#include <QtCore/QObject>
#include <QtWidgets/QAbstractButton>
#include <QtCore/QVariant>
#include "QuestionBox.hpp"
#include "GetNelsonPath.hpp"
//#include "QObjectHandleObjectAllocator.hpp"
#include "QStringConverter.hpp"
#include "HandleManager.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
QuestionBox(const std::wstring& title, 
            const std::string &question,
            const std::wstring &button1,
            const std::wstring& button2,
            const std::wstring& button3,
            const std::wstring& defaultButton,
            int numberOfButtons)
{
    return ArrayOf();
}
//=============================================================================
}
//=============================================================================
