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
#include <QtWidgets/QMainWindow>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QtGui/QAction>
#else
#include <QtWidgets/QAction>
#endif
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMessageBox>
#include <QtHelp/QHelpEngine>
#include <QtHelp/QHelpContentWidget>
#include <QtHelp/QHelpIndexWidget>
#include <QtHelp/QHelpSearchQueryWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>
//=============================================================================
class TextEdit;
//=============================================================================
class QtHelpBrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtHelpBrowserWindow();
    void
    setSource(const QString &source);
    void setContentsVisibile(bool visible);
    bool isContentsVisible();

private:
    void
    createConnections();
    void
    createHelpWindow();
};
//=============================================================================
