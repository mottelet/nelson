%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
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
% <-- Issue URL -->
% https://github.com/Nelson-numerical-software/nelson/issues/509
% <-- Short Description -->
% add horzcat vertcat generic support for class object
%=============================================================================
A = weboptions();
R = [A, A];
assert_isequal(size(struct(R)), [1 2])
assert_isequal(class(R), 'weboptions')
%=============================================================================
R = [A; A];
assert_isequal(size(struct(R)), [2 1])
assert_isequal(class(R), 'weboptions')
%=============================================================================


R = [1 2]:3;
REF = [1 2 3];
assert_isequal(R, REF);
assert_isequal(lastwarn(), _('Array used as scalar.'));
%=============================================================================
R = ([1 : 2]):3;
REF = [1 2 3];
assert_isequal(R, REF);
%=============================================================================
R = [1,2; 3, 4]:3;
REF = [1 2 3];
assert_isequal(R, REF);
%=============================================================================
R = [2:4]:[3:5]:[6:7];
REF = [2 5];
assert_isequal(R, REF);
%=============================================================================
R = []:3;
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
R = 1:2:[];
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
R = 1:[]:4;
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
R = 1:2:zeros(3, 0);
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
