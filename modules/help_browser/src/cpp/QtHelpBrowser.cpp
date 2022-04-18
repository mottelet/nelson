//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "QtHelpBrowser.h"
//=============================================================================
QtHelpBrowser::QtHelpBrowser(QHelpEngine* helpEngine, QWidget* parent)
    : QTextBrowser(parent), helpEngine(helpEngine)
{ }
//=============================================================================
QVariant
QtHelpBrowser::loadResource(int type, const QUrl& name)
{
    if (name.scheme() == "qthelp") {
        return QVariant(helpEngine->fileData(name));
    }
    return QTextBrowser::loadResource(type, name);
}
//=============================================================================
