//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "FileSystemWrapper.hpp"
#include "StartNelsonUserScript.hpp"
#include "CloseAllFiles.hpp"
#include "EvaluateScriptFile.hpp"
#include "Interface.hpp"
#include "NelsonConfiguration.hpp"
#include "i18n.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
bool
StartNelsonUserScript(Evaluator* eval)
{
    Context* ctx = eval->getContext();
    if (ctx != nullptr) {
        std::wstring prefPath = NelsonConfiguration::getInstance()->getNelsonPreferencesDirectory();
        FileSystemWrapper::Path path(prefPath);
        path += L"/startup.m";
        bool bIsFile = FileSystemWrapper::Path::is_regular_file(path);
        if (bIsFile) {
            std::wstring wstr = path.generic_wstring();
            try {
                EvaluateScriptFile(eval, wstr);
            } catch (const Exception& e) {
                // close all opened files
                CloseAllFiles();
                Interface* io = eval->getInterface();
                eval->setLastErrorException(e);
                std::wstring errmsg = _W("User startup.m failed to run.");
                if (io != nullptr) {
                    io->errorMessage(errmsg);
                } else {
                    const wchar_t* format = L"%s\n";
                    fwprintf(stderr, format, errmsg.c_str());
                }
            }
            return true;
        }
        return false;
    }
    return false;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
