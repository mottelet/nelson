//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
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
#include "double_dispBuiltin.hpp"
#include "Error.hpp"
#include "DoubleDisplay.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector Nelson::DoubleGateway::double_dispBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 0)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
	else
	{
		Class classA = argIn[0].getDataClass();
		bool isSupportedType = (classA == NLS_DCOMPLEX || classA == NLS_DOUBLE);
		if (!isSupportedType || (argIn[0].isSparse()))
		{
			Error(eval, ERROR_WRONG_ARGUMENT_1_TYPE_DOUBLE_EXPECTED);
		}
		else
		{
			DoubleDisplay(eval, argIn[0]);
		}
	}
    return retval;
}
//=============================================================================
