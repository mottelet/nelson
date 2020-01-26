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
#include "slicot_sb01bdBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    sb01bd_(const char* DICO, int* N, int* M, int* NP, double* ALPHA, double* A, int* LDA,
        const double* B, int* LDB, double* WR, double* WI, int* NFP, int* NAP, int* NUP, double* F,
        int* LDF, double* Z, int* LDZ, double* TOL, double* DWORK, int* LDWORK, int* IWARN,
        int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, WR_OUT, WI_OUT, NFP, NAP, NUP, F, Z, IWARN, INFO] = slicot_sb01bd(DICO, ALPHA, A_IN, B,
// WR_IN, WI_IN, TOL)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_sb01bdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 10) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 7) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf DICO = argIn[0];
    Dimensions dimsDICO = DICO.getDimensions();
    std::string DICO_string = DICO.getContentAsCString();
    const char* DICO_ptr = DICO_string.c_str();
    ArrayOf ALPHA = argIn[1];
    Dimensions dimsALPHA = ALPHA.getDimensions();
    ALPHA.promoteType(NLS_DOUBLE);
    double* ALPHA_ptr = (double*)ALPHA.getDataPointer();
    ArrayOf B = argIn[3];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    double* B_ptr = (double*)B.getDataPointer();
    ArrayOf TOL = argIn[6];
    Dimensions dimsTOL = TOL.getDimensions();
    TOL.promoteType(NLS_DOUBLE);
    double* TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[2];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double* A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf WR = argIn[4];
    Dimensions dimsWR = WR.getDimensions();
    WR.promoteType(NLS_DOUBLE);
    ArrayOf WR_output = WR;
    WR_output.ensureSingleOwner();
    double* WR_output_ptr = (double*)WR_output.getDataPointer();
    ArrayOf WI = argIn[5];
    Dimensions dimsWI = WI.getDimensions();
    WI.promoteType(NLS_DOUBLE);
    ArrayOf WI_output = WI;
    WI_output.ensureSingleOwner();
    double* WI_output_ptr = (double*)WI_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getRows();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getDimensions().getColumns();
    ArrayOf NP = ArrayOf::int32VectorConstructor(1);
    int* NP_ptr = (int*)NP.getDataPointer();
    NP_ptr[0] = (int)WR.getDimensions().getRows();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = std::max(1, (int)B.getDimensions().getRows());
    ArrayOf LDF = ArrayOf::int32VectorConstructor(1);
    int* LDF_ptr = (int*)LDF.getDataPointer();
    LDF_ptr[0] = std::max(1, (int)B.getDimensions().getRows());
    ArrayOf LDZ = ArrayOf::int32VectorConstructor(1);
    int* LDZ_ptr = (int*)LDZ.getDataPointer();
    LDZ_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1,
        std::max(std::max(std::max(1, 5 * (int)B.getDimensions().getColumns()),
                     5 * (int)A.getDimensions().getRows()),
            2 * (int)A.getDimensions().getRows() + 4 * (int)B.getDimensions().getColumns()));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0] = std::max(std::max(std::max(1, 5 * (int)B.getDimensions().getColumns()),
                                 5 * (int)A.getDimensions().getRows()),
        2 * (int)A.getDimensions().getRows() + 4 * (int)B.getDimensions().getColumns());
    // OUTPUT VARIABLES
    ArrayOf NFP_output = ArrayOf::int32VectorConstructor(1);
    int* NFP_output_ptr = (int*)NFP_output.getDataPointer();
    ArrayOf NAP_output = ArrayOf::int32VectorConstructor(1);
    int* NAP_output_ptr = (int*)NAP_output.getDataPointer();
    ArrayOf NUP_output = ArrayOf::int32VectorConstructor(1);
    int* NUP_output_ptr = (int*)NUP_output.getDataPointer();
    ArrayOf F_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, (int)B.getDimensions().getRows()),
        (indexType)(int)A.getDimensions().getRows());
    double* F_output_ptr = (double*)F_output.getDataPointer();
    ArrayOf Z_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, (int)A.getDimensions().getRows()),
        (indexType)(int)A.getDimensions().getRows());
    double* Z_output_ptr = (double*)Z_output.getDataPointer();
    ArrayOf IWARN_output = ArrayOf::int32VectorConstructor(1);
    int* IWARN_output_ptr = (int*)IWARN_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsDICO.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    if (!dimsALPHA.isScalar()) {
        Error(_W("Input argument #2: scalar expected."));
    }
    Dimensions dimsA_expected(
        std::max(1, (int)A.getDimensions().getRows()), (int)A.getDimensions().getRows());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #3: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    if (!dimsTOL.isScalar()) {
        Error(_W("Input argument #7: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try {
        sb01bd_(DICO_ptr, N_ptr, M_ptr, NP_ptr, ALPHA_ptr, A_output_ptr, LDA_ptr, B_ptr, LDB_ptr,
            WR_output_ptr, WI_output_ptr, NFP_output_ptr, NAP_output_ptr, NUP_output_ptr,
            F_output_ptr, LDF_ptr, Z_output_ptr, LDZ_ptr, TOL_ptr, DWORK_ptr, LDWORK_ptr,
            IWARN_output_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("sb01bd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval.push_back(A_output);
    }
    if (nLhs > 1) {
        retval.push_back(WR_output);
    }
    if (nLhs > 2) {
        retval.push_back(WI_output);
    }
    if (nLhs > 3) {
        retval.push_back(NFP_output);
    }
    if (nLhs > 4) {
        retval.push_back(NAP_output);
    }
    if (nLhs > 5) {
        retval.push_back(NUP_output);
    }
    if (nLhs > 6) {
        retval.push_back(F_output);
    }
    if (nLhs > 7) {
        retval.push_back(Z_output);
    }
    if (nLhs > 8) {
        retval.push_back(IWARN_output);
    }
    if (nLhs > 9) {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
