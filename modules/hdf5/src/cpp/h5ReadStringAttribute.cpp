//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#include "h5ReadStringAttribute.hpp"
#include "h5ReadAttributeHelpers.hpp"
#include "Exception.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
h5ReadStringAttribute(hid_t attr_id, hid_t type, hid_t aspace, std::wstring& error)
{
    ArrayOf res;
    hsize_t storageSize = H5Aget_storage_size(attr_id);
    hsize_t sizeType = H5Tget_size(type);
    size_t numVal = storageSize / sizeType;

	if (numVal == 0) {
        res = ArrayOf::characterArrayConstructor("");
    } else if (numVal == 1) {
        bool isVlenString = H5Tis_variable_str(type);
        if (isVlenString) {
            char** temp;
            try {
                temp = new_with_exception<char*>(storageSize, true);
            } catch (Exception& e) {
                error = e.getMessage();
                return res;
            }
            hid_t memtype = H5Tcopy(H5T_C_S1);
            H5Tset_size(memtype, H5T_VARIABLE);

            if (H5Aread(attr_id, memtype, temp) < 0) {
                delete[] temp;
                H5Sclose(memtype);
                error = _W("Cannot read attribute.");
                return res;
            }
            std::string str;
            str = temp[0];
            res = ArrayOf::characterArrayConstructor(str);
            herr_t err = H5Dvlen_reclaim(type, aspace, H5P_DEFAULT, temp);
            delete[] temp;
            H5Sclose(memtype);
        } else {
            char* temp;
            try {
                temp = new_with_exception<char>(storageSize, true);
            } catch (Exception& e) {
                error = e.getMessage();
                return res;
            }
            if (H5Aread(attr_id, type, temp) < 0) {
                delete[] temp;
                error = _W("Cannot read attribute.");
                return res;
            }
            indexType pos = 0;
            std::string str;
            str.reserve(sizeType);
            for (indexType l = 0; l < sizeType; l++) {
                str.push_back(temp[pos]);
                pos++;
            }
            res = ArrayOf::characterArrayConstructor(str);
        }
    } else {
        Dimensions dims = getDimensions(aspace);
        bool isVlenString = H5Tis_variable_str(type);
        ArrayOf* elements;
        try {
            if (isVlenString) {
                elements = new_with_exception<ArrayOf>(dims.getElementCount(), false);
            } else {
                elements = new_with_exception<ArrayOf>(numVal, false);
            }
            elements = new_with_exception<ArrayOf>(dims.getElementCount(), false);
        } catch (Exception& e) {
            error = e.getMessage();
            return res;
        }

        if (isVlenString) {
            char** temp;
            try {
                temp = new_with_exception<char*>(storageSize, true);
            } catch (Exception& e) {
                error = e.getMessage();
                return res;
            }
            hid_t memtype = H5Tcopy(H5T_C_S1);
            H5Tset_size(memtype, H5T_VARIABLE);

            if (H5Aread(attr_id, memtype, temp) < 0) {
                delete[] elements;
                delete[] temp;
                H5Sclose(memtype);
                error = _W("Cannot read attribute.");
                return res;
            }
            indexType pos = 0;
            for (indexType k = 0; k < dims.getElementCount(); k++) {
                std::string str;
                str = temp[k];
                elements[k] = ArrayOf::characterArrayConstructor(str);
            }
            herr_t err = H5Dvlen_reclaim(type, aspace, H5P_DEFAULT, temp);
            delete[] temp;
            H5Sclose(memtype);
        } else {
            char* temp;
            try {
                temp = new_with_exception<char>(storageSize, true);
            } catch (Exception& e) {
                error = e.getMessage();
                return res;
            }
            if (H5Aread(attr_id, type, temp) < 0) {
                delete[] elements;
                delete[] temp;
                error = _W("Cannot read attribute.");
                return res;
            }
            indexType pos = 0;
            for (indexType k = 0; k < numVal; k++) {
                std::string str;
                str.reserve(sizeType);
                for (indexType l = 0; l < sizeType; l++) {
                    str.push_back(temp[pos]);
                    pos++;
                }
                elements[k] = ArrayOf::characterArrayConstructor(str);
            }
        }
        res = ArrayOf(NLS_CELL_ARRAY, dims, elements);
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
