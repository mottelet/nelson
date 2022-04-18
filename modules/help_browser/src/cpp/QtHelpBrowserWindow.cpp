//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <QtCore/QFileInfo>
#include "QtHelpBrowserWindow.h"
#include "QtHelpBrowser.h"
#include "HelpCollection.hpp"
#include "QStringConverter.hpp"
//=============================================================================
static QtHelpBrowser* textViewer = nullptr;
static QHelpEngine* helpEngine = nullptr;
static QSplitter* horizSplitter = nullptr;
//=============================================================================
QtHelpBrowserWindow::QtHelpBrowserWindow()
{
    createHelpWindow();
    setWindowTitle(tr("Nelson's Help"));
    resize(600, 400);
}
//=============================================================================
void
QtHelpBrowserWindow::createHelpWindow()
{
    QString qhcFile = Nelson::wstringToQString(
        Nelson::HelpCollection::getInstance()->getNelsonCachedCollectionFullFilename());

    QUrl qUrl("qthelp://org.nelson.help/help/homepage.html");

    helpEngine = new QHelpEngine(qhcFile);
    if (!helpEngine->setupData()) {
        QMessageBox::warning(this, tr("Nelson Documentation"),
            tr("Could not setup the data required for the\n"
               "documentation viewer. Only help texts in\n"
               "the Console Widget will be available."));
    }
    QTabWidget* tWidget = new QTabWidget;
    tWidget->addTab(helpEngine->contentWidget(), "Contents");
    tWidget->addTab(helpEngine->indexWidget(), "Index");

    textViewer = new QtHelpBrowser(helpEngine);
    textViewer->setSource(qUrl);
    connect(helpEngine->contentWidget(), SIGNAL(linkActivated(QUrl)), textViewer,
        SLOT(setSource(QUrl)));

    connect(helpEngine->indexWidget(), SIGNAL(linkActivated(QUrl, QString)), textViewer,
        SLOT(setSource(QUrl)));

    horizSplitter = new QSplitter(Qt::Horizontal);
    horizSplitter->insertWidget(0, tWidget);
    horizSplitter->insertWidget(1, textViewer);
    this->setCentralWidget(horizSplitter);
}
//=============================================================================
void
QtHelpBrowserWindow::setSource(const QString& source)
{
    if (textViewer) {
        QUrl qUrl(source);
        textViewer->setSource(qUrl);
    }
}
//=============================================================================
void
QtHelpBrowserWindow::setContentsVisibile(bool visible)
{ 
    if (horizSplitter) {
        QTabWidget* tabs = (QTabWidget*)horizSplitter->widget(0);
        tabs->setTabVisible(0, false);
    }
}
//=============================================================================
bool
QtHelpBrowserWindow::isContentsVisible()
{
    if (helpEngine) {
        return helpEngine->contentWidget()->isVisible();
    }
    return false;
}
//=============================================================================
