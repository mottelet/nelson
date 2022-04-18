//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <cstdlib>
#include "QStringConverter.hpp"
#include "HelpCollection.hpp"
#include "QtHelpBrowserWindow.h"
#include "HelpBrowser.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static QtHelpBrowserWindow* qtHelpBrowserWindow = nullptr;
//=============================================================================
HelpBrowser* HelpBrowser::m_pInstance = nullptr;
//=============================================================================
HelpBrowser*
HelpBrowser::getInstance()
{
    if (m_pInstance == nullptr) {
        m_pInstance = new HelpBrowser();
    }
    return m_pInstance;
}
//=============================================================================
void
HelpBrowser::destroy()
{
    if (m_pInstance) {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}
//=============================================================================
void
HelpBrowser::showDocByName(const std::wstring& name)
{
    std::wstring command = std::wstring(L"activateKeyword") + std::wstring(L" ") + name;
}
//=============================================================================
void
HelpBrowser::showDocByIdentifier(const std::wstring& identifier)
{
    std::wstring command = std::wstring(L"activateIdentifier") + std::wstring(L" ") + identifier;
}
//=============================================================================
wstringVector
HelpBrowser::getAttributes()
{
    return HelpCollection::getInstance()->getRegisteredFiles();
}
//=============================================================================
bool
HelpBrowser::startBrowser(std::wstring& msg)
{
     if (qtHelpBrowserWindow == nullptr) {
        qtHelpBrowserWindow = new QtHelpBrowserWindow();
     }
     if (qtHelpBrowserWindow != nullptr) {
         qtHelpBrowserWindow->show();
         return true;
     }
     return false;
}
//=============================================================================
void
HelpBrowser::closeBrowser()
{
    if (qtHelpBrowserWindow != nullptr) {
        qtHelpBrowserWindow->close();
    }
}
//=============================================================================
bool
HelpBrowser::isVisible()
{
    bool visible = false;
    if (qtHelpBrowserWindow != nullptr) {
        visible = qtHelpBrowserWindow->isVisible();
    }
    return visible;
}
//=============================================================================
HelpBrowser::HelpBrowser() { }
//=============================================================================
void
HelpBrowser::hideContents()
{
    if (qtHelpBrowserWindow != nullptr) {
        qtHelpBrowserWindow->setContentsVisibile(false);
    }
}
//=============================================================================
void
HelpBrowser::setSource(const std::wstring& source)
{
    if (qtHelpBrowserWindow != nullptr) {
        qtHelpBrowserWindow->setSource(Nelson::wstringToQString(source));
    }
}
//=============================================================================
void
HelpBrowser::registerHelpFiles(const wstringVector& filenames)
{
    HelpCollection::getInstance()->registerHelpFiles(filenames);
}
//=============================================================================
void
HelpBrowser::unregisterHelpFiles(const wstringVector& filenames)
{
    HelpCollection::getInstance()->unregisterHelpFiles(filenames);
}
//=============================================================================
void
HelpBrowser::clearCache()
{
    closeBrowser();
    HelpCollection::getInstance()->clearCache();
}
//=============================================================================
}
//=============================================================================
