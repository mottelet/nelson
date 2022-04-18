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
#include <QtWidgets/QTextBrowser>
#include <QtHelp/QHelpEngine>
//=============================================================================
class QtHelpBrowser : public QTextBrowser
{
public:
    QtHelpBrowser(QHelpEngine* helpEngine, QWidget* parent = 0);
    QVariant
    loadResource(int type, const QUrl& name);

private:
    QHelpEngine* helpEngine;
};
//=============================================================================
