//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include <algorithm>
#include "slicot_sb03odBuiltin.hpp"
#include "Error.hpp"
#include "i18n.hpp"
#include "CheckerHelpers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    sb03od_(const char* DICO, const char* FACT, const char* TRANS, int* N, int* M, const double* A,
        int* LDA, double* Q, int* LDQ, double* B, int* LDB, double* SCALE, double* WR, double* WI,
        double* DWORK, int* LDWORK, int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [Q_OUT, B_OUT, SCALE, WR, WI, INFO] = slicot_sb03od(DICO, FACT, TRANS, A, Q_IN, B_IN)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_sb03odBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 6);
    nargincheck(argIn, 6, 6);
    // INPUT VARIABLES
    ArrayOf DICO = argIn[0];
    Dimensions dimsDICO = DICO.getDimensions();
    std::string DICO_string = DICO.getContentAsCString();
    const char* DICO_ptr = DICO_string.c_str();
    ArrayOf FACT = argIn[1];
    Dimensions dimsFACT = FACT.getDimensions();
    std::string FACT_string = FACT.getContentAsCString();
    const char* FACT_ptr = FACT_string.c_str();
    ArrayOf TRANS = argIn[2];
    Dimensions dimsTRANS = TRANS.getDimensions();
    std::string TRANS_string = TRANS.getContentAsCString();
    const char* TRANS_ptr = TRANS_string.c_str();
    ArrayOf A = argIn[3];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    double* A_ptr = (double*)A.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf Q = argIn[4];
    Dimensions dimsQ = Q.getDimensions();
    Q.promoteType(NLS_DOUBLE);
    ArrayOf Q_output = Q;
    Q_output.ensureSingleOwner();
    double* Q_output_ptr = (double*)Q_output.getDataPointer();
    ArrayOf B = argIn[5];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    ArrayOf B_output = B;
    B_output.ensureSingleOwner();
    double* B_output_ptr = (double*)B_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getRows();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getRows();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDQ = ArrayOf::int32VectorConstructor(1);
    int* LDQ_ptr = (int*)LDQ.getDataPointer();
    LDQ_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = TRANS.getContentAsCString().compare("N") == 0
        ? std::max(1, std::max((int)A.getRows(), (int)B.getRows()))
        : std::max(1, (int)A.getRows());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(
        1, std::max(1, 4 * (int)A.getRows() + std::min((int)B.getRows(), (int)A.getRows())));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0]
        = std::max(1, 4 * (int)A.getRows() + std::min((int)B.getRows(), (int)A.getRows()));
    // OUTPUT VARIABLES
    ArrayOf SCALE_output = ArrayOf::doubleVectorConstructor(1);
    double* SCALE_output_ptr = (double*)SCALE_output.getDataPointer();
    ArrayOf WR_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getRows());
    double* WR_output_ptr = (double*)WR_output.getDataPointer();
    ArrayOf WI_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getRows());
    double* WI_output_ptr = (double*)WI_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsDICO.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    if (!dimsFACT.isScalar()) {
        Error(_W("Input argument #2: scalar expected."));
    }
    if (!dimsTRANS.isScalar()) {
        Error(_W("Input argument #3: scalar expected."));
    }
    Dimensions dimsQ_expected(std::max(1, (int)A.getRows()), (int)A.getRows());
    if (!dimsQ.equals(dimsQ_expected)) {
        Error(_("Input argument #5: wrong size.") + " " + dimsQ_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsB_expected(TRANS.getContentAsCString().compare("N") == 0
            ? std::max(1, std::max((int)A.getRows(), (int)B.getRows()))
            : std::max(1, (int)A.getRows()),
        (int)A.getRows());
    if (!dimsB.equals(dimsB_expected)) {
        Error(_("Input argument #6: wrong size.") + " " + dimsB_expected.toString() + " "
            + "expected" + ".");
    }
    // CALL EXTERN FUNCTION
    try {
        sb03od_(DICO_ptr, FACT_ptr, TRANS_ptr, N_ptr, M_ptr, A_ptr, LDA_ptr, Q_output_ptr, LDQ_ptr,
            B_output_ptr, LDB_ptr, SCALE_output_ptr, WR_output_ptr, WI_output_ptr, DWORK_ptr,
            LDWORK_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("sb03od function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval << Q_output;
    }
    if (nLhs > 1) {
        retval << B_output;
    }
    if (nLhs > 2) {
        retval << SCALE_output;
    }
    if (nLhs > 3) {
        retval << WR_output;
    }
    if (nLhs > 4) {
        retval << WI_output;
    }
    if (nLhs > 5) {
        retval << INFO_output;
    }
    return retval;
}
//=============================================================================
