//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "slicot_sb04qdBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    sb04qd_(int* N, int* M, double* A, int* LDA, double* B, int* LDB, double* C, int* LDC,
        double* Z, int* LDZ, int* IWORK, double* DWORK, int* LDWORK, int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, B_OUT, C_OUT, Z, INFO] = slicot_sb04qd(A_IN, B_IN, C_IN)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_sb04qdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 5) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 3) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    // IN/OUT VARIABLES
    ArrayOf A = argIn[0];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double* A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf B = argIn[1];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    ArrayOf B_output = B;
    B_output.ensureSingleOwner();
    double* B_output_ptr = (double*)B_output.getDataPointer();
    ArrayOf C = argIn[2];
    Dimensions dimsC = C.getDimensions();
    C.promoteType(NLS_DOUBLE);
    ArrayOf C_output = C;
    C_output.ensureSingleOwner();
    double* C_output_ptr = (double*)C_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getColumns();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getDimensions().getRows();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getDimensions().getColumns());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = std::max(1, (int)B.getDimensions().getRows());
    ArrayOf LDC = ArrayOf::int32VectorConstructor(1);
    int* LDC_ptr = (int*)LDC.getDataPointer();
    LDC_ptr[0] = std::max(1, (int)B.getDimensions().getRows());
    ArrayOf LDZ = ArrayOf::int32VectorConstructor(1);
    int* LDZ_ptr = (int*)LDZ.getDataPointer();
    LDZ_ptr[0] = std::max(1, (int)B.getDimensions().getRows());
    ArrayOf IWORK = ArrayOf::int32Matrix2dConstructor(1, 4 * (int)A.getDimensions().getColumns());
    int* IWORK_ptr = (int*)IWORK.getDataPointer();
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1,
        std::max(std::max(std::max(1,
                              2 * (int)A.getDimensions().getColumns()
                                      * (int)A.getDimensions().getColumns()
                                  + 9 * (int)A.getDimensions().getColumns()),
                     5 * (int)B.getDimensions().getRows()),
            (int)A.getDimensions().getColumns() + (int)B.getDimensions().getRows()));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0] = std::max(
        std::max(std::max(1,
                     2 * (int)A.getDimensions().getColumns() * (int)A.getDimensions().getColumns()
                         + 9 * (int)A.getDimensions().getColumns()),
            5 * (int)B.getDimensions().getRows()),
        (int)A.getDimensions().getColumns() + (int)B.getDimensions().getRows());
    // OUTPUT VARIABLES
    ArrayOf Z_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, (int)B.getDimensions().getRows()),
        (indexType)(int)B.getDimensions().getRows());
    double* Z_output_ptr = (double*)Z_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    Dimensions dimsA_expected(
        std::max(1, (int)A.getDimensions().getColumns()), (int)A.getDimensions().getColumns());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #1: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsB_expected(
        std::max(1, (int)B.getDimensions().getRows()), (int)B.getDimensions().getRows());
    if (!dimsB.equals(dimsB_expected)) {
        Error(_("Input argument #2: wrong size.") + " " + dimsB_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsC_expected(
        std::max(1, (int)B.getDimensions().getRows()), (int)B.getDimensions().getRows());
    if (!dimsC.equals(dimsC_expected)) {
        Error(_("Input argument #3: wrong size.") + " " + dimsC_expected.toString() + " "
            + "expected" + ".");
    }
    // CALL EXTERN FUNCTION
    try {
        sb04qd_(N_ptr, M_ptr, A_output_ptr, LDA_ptr, B_output_ptr, LDB_ptr, C_output_ptr, LDC_ptr,
            Z_output_ptr, LDZ_ptr, IWORK_ptr, DWORK_ptr, LDWORK_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("sb04qd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval.push_back(A_output);
    }
    if (nLhs > 1) {
        retval.push_back(B_output);
    }
    if (nLhs > 2) {
        retval.push_back(C_output);
    }
    if (nLhs > 3) {
        retval.push_back(Z_output);
    }
    if (nLhs > 4) {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
