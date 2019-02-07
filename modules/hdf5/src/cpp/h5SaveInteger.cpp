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
#include "h5SaveInteger.hpp"
#include "h5SaveLoadHelpers.hpp"
#include "h5SaveHelpers.hpp"
#include "Exception.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static bool
h5SaveIntegerEmptyMatrix(
    hid_t fid, const std::string& location, const std::string& variableName, ArrayOf VariableValue);
//=============================================================================
bool
h5SaveInteger(hid_t fid, const std::string& location, const std::string& variableName,
    ArrayOf VariableValue, bool useCompression)
{
    if (VariableValue.isEmpty(false)) {
        return h5SaveIntegerEmptyMatrix(fid, location, variableName, VariableValue);
    }
    bool bSuccess = false;
    std::string h5path;
    if (location == "/") {
        h5path = location + variableName;
    } else {
        h5path = location + "/" + variableName;
    }
    herr_t status = H5Ldelete(fid, h5path.c_str(), H5P_DEFAULT);

    hid_t dspace_id = H5I_INVALID_HID;
    hid_t type_id = H5I_INVALID_HID;
    void* buffer = nullptr;

    switch (VariableValue.getDataClass()) {
    case NLS_INT8: {
        type_id = H5Tcopy(H5T_NATIVE_INT8);
    } break;
    case NLS_UINT8: {
        type_id = H5Tcopy(H5T_NATIVE_UINT8);
    } break;
    case NLS_INT16: {
        type_id = H5Tcopy(H5T_NATIVE_INT16);
    } break;
    case NLS_UINT16: {
        type_id = H5Tcopy(H5T_NATIVE_UINT16);
    } break;
    case NLS_INT32: {
        type_id = H5Tcopy(H5T_NATIVE_INT32);
    } break;
    case NLS_UINT32: {
        type_id = H5Tcopy(H5T_NATIVE_UINT32);
    } break;
    case NLS_INT64: {
        type_id = H5Tcopy(H5T_NATIVE_INT64);
    } break;
    case NLS_UINT64: {
        type_id = H5Tcopy(H5T_NATIVE_UINT64);
    } break;
    default: { } break; }
    Dimensions dimsValue = VariableValue.getDimensions();
    hsize_t* dimsAsHsize_t = nullptr;
    indexType nbElementsSizeData;
    if (dimsValue.isScalar()) {
        try {
            dimsAsHsize_t = new_with_exception<hsize_t>(1, true);
        } catch (Exception&) {
            return false;
        }
        nbElementsSizeData = 1;
        dimsAsHsize_t[0] = 1;
        dspace_id = H5Screate_simple((int)1, dimsAsHsize_t, dimsAsHsize_t);
    } else {
        try {
            dimsAsHsize_t = new_with_exception<hsize_t>(dimsValue.getLength(), true);
        } catch (Exception&) {
            return false;
        }
        nbElementsSizeData = dimsValue.getLength();
        for (indexType k = 1; k <= nbElementsSizeData; k++) {
            dimsAsHsize_t[k - 1] = (hsize_t)dimsValue[nbElementsSizeData - k];
        }
        dspace_id = H5Screate_simple((int)dimsValue.getLength(), dimsAsHsize_t, dimsAsHsize_t);
    }
    delete[] dimsAsHsize_t;
    hid_t plist = setCompression(dimsValue, useCompression);
    buffer = (void*)VariableValue.getDataPointer();
    hid_t dataset_id
        = H5Dcreate(fid, h5path.c_str(), type_id, dspace_id, H5P_DEFAULT, plist, H5P_DEFAULT);
    status = H5Dwrite(dataset_id, type_id, H5S_ALL, H5S_ALL, H5P_DEFAULT, buffer);
    H5Pclose(plist);
    H5Dclose(dataset_id);
    H5Sclose(dspace_id);
    if (status < 0) {
        bSuccess = false;
    } else {
        bSuccess = h5SaveClassAttribute(fid, h5path, VariableValue);
        if (bSuccess) {
            bSuccess = h5SaveDimensionsAttribute(fid, h5path, dimsValue);
        }
    }
    return bSuccess;
}
//=============================================================================
bool
h5SaveIntegerEmptyMatrix(
    hid_t fid, const std::string& location, const std::string& variableName, ArrayOf VariableValue)
{
    bool bSuccess = false;
    std::string h5path;
    if (location == "/") {
        h5path = location + variableName;
    } else {
        h5path = location + "/" + variableName;
    }
    herr_t status = H5Ldelete(fid, h5path.c_str(), H5P_DEFAULT);

    int8 i8value = (int8)0;
    uint8 ui8value = (uint8)0;
    int16 i16value = (int16)0;
    uint16 ui16value = (uint16)0;
    int32 i32value = (int32)0;
    uint32 ui32value = (uint32)0;
    int64 i64value = (int64)0;
    uint64 ui64value = (uint64)0;
    void* ptr;
    hid_t type_id;
    switch (VariableValue.getDataClass()) {
    case NLS_INT8: {
        ptr = &i8value;
        type_id = H5Tcopy(H5T_NATIVE_INT8);
    } break;
    case NLS_INT16: {
        ptr = &i16value;
        type_id = H5Tcopy(H5T_NATIVE_INT16);
    } break;
    case NLS_INT32: {
        ptr = &i32value;
        type_id = H5Tcopy(H5T_NATIVE_INT32);
    } break;
    case NLS_INT64: {
        ptr = &i64value;
        type_id = H5Tcopy(H5T_NATIVE_INT64);
    } break;
    case NLS_UINT8: {
        ptr = &ui8value;
        type_id = H5Tcopy(H5T_NATIVE_UINT8);
    } break;
    case NLS_UINT16: {
        ptr = &ui16value;
        type_id = H5Tcopy(H5T_NATIVE_UINT16);
    } break;
    case NLS_UINT32: {
        ptr = &ui32value;
        type_id = H5Tcopy(H5T_NATIVE_UINT32);
    } break;
    default:
    case NLS_UINT64: {
        ptr = &ui64value;
        type_id = H5Tcopy(H5T_NATIVE_UINT64);
    } break;
    }
    hsize_t dimsAsHsize_t[1];
    dimsAsHsize_t[0] = 1;
    hid_t dspace_id = H5Screate_simple((int)1, dimsAsHsize_t, dimsAsHsize_t);
    if (dspace_id < 0) {
        return false;
    }

    hid_t dataset_id
        = H5Dcreate(fid, h5path.c_str(), type_id, dspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    if (dataset_id < 0) {
        return false;
    }
    status = H5Dwrite(dataset_id, type_id, H5S_ALL, H5S_ALL, H5P_DEFAULT, ptr);

    H5Dclose(dataset_id);
    H5Sclose(dspace_id);
    if (status < 0) {
        return false;
    }
    bSuccess = h5SaveEmptyAttribute(fid, h5path);
    if (!bSuccess) {
        return false;
    }
    bSuccess = h5SaveClassAttribute(fid, h5path, VariableValue);
    if (bSuccess) {
        if (VariableValue.isComplex()) {
            bSuccess = h5SaveComplexAttribute(fid, h5path);
        }
        if (bSuccess) {
            bSuccess = h5SaveDimensionsAttribute(fid, h5path, VariableValue.getDimensions());
            if (bSuccess && VariableValue.isSparse()) {
                h5SaveSparseAttribute(fid, h5path);
            }
        }
    }
    return bSuccess;
}
//=============================================================================
};
//=============================================================================
