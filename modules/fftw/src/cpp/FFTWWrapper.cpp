//=============================================================================
// Copyright (c) 2016-2019 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "FFTWDynamicLibrary.hpp"
#include "FFTWWrapper.hpp"
#include "dynamic_library.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static bool fftwLoaded = false;
static library_handle fftw_handle = nullptr;
static library_handle fftwf_handle = nullptr;
//=============================================================================
using PROC_fftw_execute = void (*)(const fftw_plan plan);
using PROC_fftw_plan_dft_1d
    = fftw_plan (*)(int n, fftw_complex* in, fftw_complex* out, int sign, unsigned flags);
using PROC_fftw_destroy_plan = void (*)(fftw_plan plan);
using PROC_fftw_forget_wisdom = void (*)(void);
using PROC_fftw_export_wisdom_to_string = char* (*)(void);
using PROC_fftw_import_wisdom_from_string = int (*)(const char* input_string);
using PROC_fftw_malloc = void* (*)(size_t n);
using PROC_fftw_free = void (*)(void* p);
//=============================================================================
using PROC_fftwf_execute = void (*)(const fftwf_plan plan);
using PROC_fftwf_destroy_plan = void (*)(fftwf_plan plan);
using PROC_fftwf_free = void (*)(void* p);
using PROC_fftwf_malloc = void* (*)(size_t n);
using PROC_fftwf_import_wisdom_from_string = int (*)(const char* input_string);
using PROC_fftwf_export_wisdom_to_string = char* (*)(void);
using PROC_fftwf_forget_wisdom = void (*)(void);
using PROC_fftwf_plan_dft_1d
    = fftwf_plan (*)(int n, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags);
//=============================================================================
PROC_fftw_execute fftw_executePtr = nullptr;
PROC_fftw_plan_dft_1d fftw_plan_dft_1dPtr = nullptr;
PROC_fftw_destroy_plan fftw_destroy_planPtr = nullptr;
PROC_fftw_forget_wisdom fftw_forget_wisdomPtr = nullptr;
PROC_fftw_export_wisdom_to_string fftw_export_wisdom_to_stringPtr = nullptr;
PROC_fftw_import_wisdom_from_string fftw_import_wisdom_from_stringPtr = nullptr;
PROC_fftw_malloc fftw_mallocPtr = nullptr;
PROC_fftw_free fftw_freePtr = nullptr;
//=============================================================================
PROC_fftwf_execute fftwf_executePtr = nullptr;
PROC_fftwf_plan_dft_1d fftwf_plan_dft_1dPtr = nullptr;
PROC_fftwf_destroy_plan fftwf_destroy_planPtr = nullptr;
PROC_fftwf_forget_wisdom fftwf_forget_wisdomPtr = nullptr;
PROC_fftwf_export_wisdom_to_string fftwf_export_wisdom_to_stringPtr = nullptr;
PROC_fftwf_import_wisdom_from_string fftwf_import_wisdom_from_stringPtr = nullptr;
PROC_fftwf_malloc fftwf_mallocPtr = nullptr;
PROC_fftwf_free fftwf_freePtr = nullptr;
//=============================================================================
static bool
loadFTTWFSymbols()
{
    fftwf_executePtr
        = reinterpret_cast<PROC_fftwf_execute>(get_function(fftwf_handle, "fftwf_execute"));
    if (!fftwf_executePtr) {
        return false;
    }
    fftwf_plan_dft_1dPtr
        = reinterpret_cast<PROC_fftwf_plan_dft_1d>(get_function(fftwf_handle, "fftwf_plan_dft_1d"));
    if (!fftwf_plan_dft_1dPtr) {
        return false;
    }
    fftwf_destroy_planPtr = reinterpret_cast<PROC_fftwf_destroy_plan>(
        get_function(fftwf_handle, "fftwf_destroy_plan"));
    if (!fftwf_destroy_planPtr) {
        return false;
    }
    fftwf_forget_wisdomPtr = reinterpret_cast<PROC_fftwf_forget_wisdom>(
        get_function(fftwf_handle, "fftwf_forget_wisdom"));
    if (!fftwf_forget_wisdomPtr) {
        return false;
    }
    fftwf_export_wisdom_to_stringPtr = reinterpret_cast<PROC_fftwf_export_wisdom_to_string>(
        get_function(fftwf_handle, "fftwf_export_wisdom_to_string"));
    if (!fftwf_export_wisdom_to_stringPtr) {
        return false;
    }
    fftwf_import_wisdom_from_stringPtr = reinterpret_cast<PROC_fftwf_import_wisdom_from_string>(
        get_function(fftwf_handle, "fftwf_import_wisdom_from_string"));
    if (!fftwf_import_wisdom_from_stringPtr) {
        return false;
    }
    fftwf_mallocPtr
        = reinterpret_cast<PROC_fftwf_malloc>(get_function(fftwf_handle, "fftwf_malloc"));
    if (!fftwf_mallocPtr) {
        return false;
    }
    fftwf_freePtr = reinterpret_cast<PROC_fftwf_free>(get_function(fftwf_handle, "fftwf_free"));
    if (!fftwf_freePtr) {
        return false;
    }
    return true;
}
//=============================================================================
static bool
loadFTTWSymbols()
{
    fftw_executePtr
        = reinterpret_cast<PROC_fftw_execute>(get_function(fftw_handle, "fftw_execute"));
    if (!fftw_executePtr) {
        return false;
    }
    fftw_plan_dft_1dPtr
        = reinterpret_cast<PROC_fftw_plan_dft_1d>(get_function(fftw_handle, "fftw_plan_dft_1d"));
    if (!fftw_plan_dft_1dPtr) {
        return false;
    }
    fftw_destroy_planPtr
        = reinterpret_cast<PROC_fftw_destroy_plan>(get_function(fftw_handle, "fftw_destroy_plan"));
    if (!fftw_destroy_planPtr) {
        return false;
    }
    fftw_forget_wisdomPtr = reinterpret_cast<PROC_fftw_forget_wisdom>(
        get_function(fftw_handle, "fftw_forget_wisdom"));
    if (!fftw_forget_wisdomPtr) {
        return false;
    }
    fftw_export_wisdom_to_stringPtr = reinterpret_cast<PROC_fftw_export_wisdom_to_string>(
        get_function(fftw_handle, "fftw_export_wisdom_to_string"));
    if (!fftw_export_wisdom_to_stringPtr) {
        return false;
    }
    fftw_import_wisdom_from_stringPtr = reinterpret_cast<PROC_fftw_import_wisdom_from_string>(
        get_function(fftw_handle, "fftw_import_wisdom_from_string"));
    if (!fftw_import_wisdom_from_stringPtr) {
        return false;
    }
    fftw_mallocPtr = reinterpret_cast<PROC_fftw_malloc>(get_function(fftw_handle, "fftw_malloc"));
    if (!fftw_mallocPtr) {
        return false;
    }
    fftw_freePtr = reinterpret_cast<PROC_fftw_free>(get_function(fftw_handle, "fftw_free"));
    if (!fftw_freePtr) {
        return false;
    }
    return true;
}
//=============================================================================
bool
freeFFTWLibrary()
{
    if (fftwLoaded) {
        fftw_executePtr = nullptr;
        fftw_plan_dft_1dPtr = nullptr;
        fftw_destroy_planPtr = nullptr;
        fftw_forget_wisdomPtr = nullptr;
        fftw_export_wisdom_to_stringPtr = nullptr;
        fftw_import_wisdom_from_stringPtr = nullptr;
        fftw_mallocPtr = nullptr;
        fftw_freePtr = nullptr;
        fftwf_executePtr = nullptr;
        fftwf_plan_dft_1dPtr = nullptr;
        fftwf_destroy_planPtr = nullptr;
        fftwf_forget_wisdomPtr = nullptr;
        fftwf_export_wisdom_to_stringPtr = nullptr;
        fftwf_import_wisdom_from_stringPtr = nullptr;
        fftwf_mallocPtr = nullptr;
        fftwf_freePtr = nullptr;

        close_dynamic_library(fftw_handle);
        close_dynamic_library(fftwf_handle);
        return true;
    }
    return false;
}
//=============================================================================
bool
loadFFTWLibrary(void)
{
#ifdef _MSC_VER
    std::wstring fftwLibraryName = L"libfftw3-3.dll";
    std::wstring fftwfLibraryName = L"libfftw3f-3.dll";
    return loadFFTWLibrary(fftwLibraryName, fftwfLibraryName);
#else
    std::string fftwLibraryName = "libfftw3" + get_dynamic_library_extension();
    std::string fftwfLibraryName = "libfftw3f" + get_dynamic_library_extension();
    bool res = loadFFTWLibrary(utf8_to_wstring(fftwLibraryName), utf8_to_wstring(fftwfLibraryName));
    if (!res) {
        std::string fftwLibraryName = "libfftw3" + get_dynamic_library_extension() + ".3";
        std::string fftwfLibraryName = "libfftw3f" + get_dynamic_library_extension() + ".3";
        res = loadFFTWLibrary(utf8_to_wstring(fftwLibraryName), utf8_to_wstring(fftwfLibraryName));
    }
    return res;
#endif
}
//=============================================================================
bool
loadFFTWLibrary(const std::wstring &fftwLibraryName, const std::wstring &fftwfLibraryName)
{
#ifdef _MSC_VER
    fftw_handle = load_dynamic_libraryW(fftwLibraryName);
    fftwf_handle = load_dynamic_libraryW(fftwfLibraryName);
#else
    fftw_handle = load_dynamic_library(wstring_to_utf8(fftwLibraryName));
    fftwf_handle = load_dynamic_library(wstring_to_utf8(fftwfLibraryName));
#endif
    if (fftw_handle != nullptr && fftwf_handle != nullptr) {
        fftwLoaded = loadFTTWSymbols() && loadFTTWFSymbols();
    } else {
        fftwLoaded = false;
    }
    return fftwLoaded;
}
//=============================================================================
void
dyn_fftw_execute(const fftw_plan plan)
{
    fftw_executePtr(plan);
}
//=============================================================================
fftw_plan
dyn_fftw_plan_dft_1d(int n, fftw_complex* in, fftw_complex* out, int sign, unsigned flags)
{
    return fftw_plan_dft_1dPtr(n, in, out, sign, flags);
}
//=============================================================================
void
dyn_fftw_destroy_plan(fftw_plan plan)
{
    fftw_destroy_planPtr(plan);
}
//=============================================================================
void
dyn_fftw_forget_wisdom(void)
{
    fftw_forget_wisdomPtr();
}
//=============================================================================
char*
dyn_fftw_export_wisdom_to_string(void)
{
    return fftw_export_wisdom_to_stringPtr();
}
//=============================================================================
int
dyn_fftw_import_wisdom_from_string(const char* input_string)
{
    return fftw_import_wisdom_from_stringPtr(input_string);
}
//=============================================================================
void*
dyn_fftw_malloc(size_t n)
{
    return fftw_mallocPtr(n);
}
//=============================================================================
void
dyn_fftw_free(void* p)
{
    fftw_freePtr(p);
}
//=============================================================================
void
dyn_fftwf_execute(const fftwf_plan plan)
{
    fftwf_executePtr(plan);
}
//=============================================================================
void
dyn_fftwf_destroy_plan(fftwf_plan plan)
{
    fftwf_destroy_planPtr(plan);
}
//=============================================================================
void
dyn_fftwf_free(void* p)
{
    fftwf_freePtr(p);
}
//=============================================================================
void*
dyn_fftwf_malloc(size_t n)
{
    return fftwf_mallocPtr(n);
}
//=============================================================================
int
dyn_fftwf_import_wisdom_from_string(const char* input_string)
{
    return fftwf_import_wisdom_from_stringPtr(input_string);
}
//=============================================================================
char*
dyn_fftwf_export_wisdom_to_string(void)
{
    return fftwf_export_wisdom_to_stringPtr();
}
//=============================================================================
void
dyn_fftwf_forget_wisdom(void)
{
    fftwf_forget_wisdomPtr();
}
//=============================================================================
fftwf_plan
dyn_fftwf_plan_dft_1d(int n, fftwf_complex* in, fftwf_complex* out, int sign, unsigned flags)
{
    return fftwf_plan_dft_1dPtr(n, in, out, sign, flags);
}
//=============================================================================
}
//=============================================================================
