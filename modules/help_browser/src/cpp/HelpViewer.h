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
#include <QtGui/QWheelEvent>
#include <QtHelp/QHelpLink>
#include <QtHelp/QHelpEngine>
//=============================================================================
class HelpViewer : public QTextBrowser
{
    Q_OBJECT

public:
    HelpViewer(QHelpEngine* helpEngine, const QUrl& homepageUrl, QWidget* parent = 0);
    virtual QVariant
    loadResource(int type, const QUrl& url);

public slots:
    void
    goHomePage();

    void
    setUrlSource(const QUrl& url);
    void
    indexActivated(const QHelpLink& document, const QString& keyword);
    void
    indexesActivated(const QList<QHelpLink>& documents, const QString& keyword);

    void
    setZoomIn(void);
    void
    setZoomOut(void);
    void
    setZoomDefault(void);

    void
    printCurrent(void);

private:
    QUrl homepage;
    QHelpEngine* helpEngine;
    int zoomLevel;
    enum
    {
        MIN_ZOOM = -5,
        MAX_ZOOM = 10
    };

protected:
    void
    wheelEvent(QWheelEvent* we);
};
//=============================================================================
