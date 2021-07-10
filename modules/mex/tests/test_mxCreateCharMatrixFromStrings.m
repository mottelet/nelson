%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
if exist('mxCreateCharMatrixFromStrings') == 0
    test_dir = [tempdir(), 'mxCreateCharMatrixFromStrings'];
    if isdir(test_dir)
        rmdir(test_dir,'s');
    end
    mkdir(test_dir);
    status = copyfile('mxCreateCharMatrixFromStrings.c', test_dir);
    assert_istrue(status);
    cd(test_dir);
    mex('mxCreateCharMatrixFromStrings.c');
    addpath(pwd())
end
%=============================================================================
R = mxCreateCharMatrixFromStrings();
assert_isequal(size(R), [3 21]);
assert_isequal(double(R(1, :)), [118, 97, 108, 117, 101, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
assert_isequal(double(R(2, :)), [97, 110, 111, 116, 104, 101, 114, 32, 118, 97, 108, 117, 101, 0, 0, 0, 0, 0, 0, 0, 0]);
assert_isequal(double(R(3, :)), [97, 110, 111, 116, 104, 101, 114, 32, 118, 97, 108, 117, 101, 32, 108, 111, 110, 103, 101, 115, 116]);
%=============================================================================
