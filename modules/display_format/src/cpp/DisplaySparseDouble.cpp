//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
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
#include <fmt/printf.h>
#include <fmt/format.h>
#include <fmt/xchar.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "DisplayDouble.hpp"
#include "NelsonConfiguration.hpp"
#include "DisplayVariableHelpers.hpp"
#include "IEEEFP.hpp"
#include "FormatHelpers.hpp"
#include "ArrayOfFormatInfo.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
#define MIDDLE_MULTIPLY "\U000000D7"
#define BLANKS_INTEGER_AT_BOL L"   "
#define LENGTH_BLANKS_INTEGER_AT_BOL 3
#define LENGTH_BLANKS_BETWEEN_INDEX_AND_NUMBER_BANK 3
#define LENGTH_BLANKS_BETWEEN_INDEX_AND_NUMBER_HEX 6
#define LENGTH_BLANKS_BETWEEN_INDEX_AND_NUMBER_PLUS 3
#define LENGTH_BLANKS_BETWEEN_INDEX_AND_NUMBER_RATIONAL 6
//============================================================================
static void
DisplayEmptySparseDouble(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing);
//=============================================================================
static void
DisplaySparseDouble(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing);
//=============================================================================
static void
DisplaySparseDoubleScalar(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing);
//=============================================================================
void
DisplaySparseDouble(Interface* io, const ArrayOf& A, const std::wstring& name)
{
    NumericFormatDisplay currentNumericFormat
        = NelsonConfiguration::getInstance()->getNumericFormatDisplay();
    LineSpacingDisplay currentLineSpacing
        = NelsonConfiguration::getInstance()->getLineSpacingDisplay();

    DisplayVariableHeader(io, A, name);
    bool withFooter = false;
    if (A.isEmpty()) {
        DisplayEmptySparseDouble(io, A, name, currentNumericFormat, currentLineSpacing);
        withFooter = !name.empty();
    } else {
        if (A.getNonzeros() == 1) {
            DisplaySparseDoubleScalar(io, A, name, currentNumericFormat, currentLineSpacing);
        } else {
            DisplaySparseDouble(io, A, name, currentNumericFormat, currentLineSpacing);
        }
        if (A.isScalar() || A.isRowVector()) {
            withFooter = !name.empty();
        } else {
            withFooter = true;
        }
    }
    if (withFooter) {
        DisplayVariableFooter(io, A, name);
    }
}
//=============================================================================
void
DisplayEmptySparseDouble(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing)
{}
//=============================================================================
void
DisplaySparseDoubleScalar(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing)
{
    indexType nbRows = A.getRows();
    indexType nbCols = A.getColumns();

    Eigen::SparseMatrix<double, 0, signedIndexType>* spMat
        = (Eigen::SparseMatrix<double, 0, signedIndexType>*)A.getSparseDataPointer();

    indexType r = 0;
    indexType c = 0;
    for (indexType k = 0; k < (indexType)spMat->outerSize(); ++k) {
        for (Eigen::SparseMatrix<double, 0, signedIndexType>::InnerIterator it(*spMat, k); it;
             ++it) {
            r = it.row() + 1;
            c = it.col() + 1;
        }
    }
    std::wstring formatIndex = _W("(%lu,%lu)");
    std::wstring indexAsString = fmt::sprintf(formatIndex, (long long)r, (long long)c);
    size_t maxLenIndexString = indexAsString.length();

    const double* values = spMat->valuePtr();
    double value = values[0];
    std::wstring asStr = formatNumber(values[0], currentNumericFormat, false);
    indexAsString = fmt::sprintf(formatIndex, (long long)r, (long long)c);
    std::wstring blanks(maxLenIndexString - indexAsString.length(), L' ');
    std::wstring msg = BLANKS_AT_BOL + centerText(indexAsString, maxLenIndexString) + BLANKS_BETWEEN
        + asStr + L"\n";
    io->outputMessage(msg);
}
//=============================================================================
static void
DisplaySparseDouble(Interface* io, const ArrayOf& A, const std::wstring& name,
    NumericFormatDisplay currentNumericFormat, LineSpacingDisplay currentLineSpacing)
{
    indexType nbRows = A.getRows();
    indexType nbCols = A.getColumns();

    if (A.getNonzeros() == 0) {
        std::wstring format = _W("All zero sparse: %s");
        std::wstring msg = fmt::sprintf(format, A.getDimensions().toWideString());
        io->outputMessage(BLANKS_AT_BOL + msg + L"\n");
        return;
    }

    Eigen::SparseMatrix<double, 0, signedIndexType>* spMat
        = (Eigen::SparseMatrix<double, 0, signedIndexType>*)A.getSparseDataPointer();

    indexType rMax = 0;
    indexType cMax = 0;
    for (indexType k = 0; k < (indexType)spMat->outerSize(); ++k) {
        for (Eigen::SparseMatrix<double, 0, signedIndexType>::InnerIterator it(*spMat, k); it;
             ++it) {
            rMax = std::max((long long)rMax, (long long)it.row() + 1);
            cMax = std::max((long long)cMax, (long long)it.col() + 1);
        }
    }

    std::wstring formatIndex = _W("(%lu,%lu)");
    std::wstring indexAsString = fmt::sprintf(formatIndex, (long long)rMax, (long long)cMax);
    size_t maxLenIndexString = indexAsString.length();

    FormatDisplayInformation formatInfo = computeFormatInfo(A, currentNumericFormat);

    if (formatInfo.scaleFactor != 1) {
        std::wstring scaleFactorAsString = formatScaleFactor(formatInfo);
        io->outputMessage(BLANKS_AT_BOL + scaleFactorAsString + L"\n");
        if (currentLineSpacing == NLS_LINE_SPACING_LOOSE) {
            io->outputMessage(L"\n");
        }
    }
    bool continueDisplay = true;
    indexType block_page = 0;
    std::wstring buffer;

    for (indexType k = 0; k < (indexType)spMat->outerSize() && continueDisplay; ++k) {
        if (NelsonConfiguration::getInstance()->getInterruptPending()) {
            continueDisplay = false;
            break;
        }
        for (Eigen::SparseMatrix<double, 0, signedIndexType>::InnerIterator it(*spMat, k);
             it && continueDisplay; ++it) {
            if (NelsonConfiguration::getInstance()->getInterruptPending()) {
                continueDisplay = false;
                break;
            }
            double value = it.value();
            std::wstring asStr = formatElement(value, currentNumericFormat, formatInfo);
            std::wstring indexAsString
                = fmt::sprintf(formatIndex, (long long)(it.row() + 1), (long long)(it.col() + 1));
            buffer.append(BLANKS_AT_BOL);
            buffer.append(
                centerText(indexAsString, maxLenIndexString) + BLANKS_BETWEEN + asStr + L"\n");
            if (block_page >= io->getTerminalHeight()) {
                io->outputMessage(buffer);
                buffer.clear();
                block_page = 0;
            } else {
                block_page++;
            }
        }
        if (!buffer.empty()) {
            io->outputMessage(buffer);
            buffer.clear();
            block_page = 0;
        }
    }
}
//=============================================================================
} // namespace Nelson
//=============================================================================