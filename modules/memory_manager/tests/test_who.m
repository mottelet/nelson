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
assert_isequal(nargin('who'), 1);
assert_isequal(nargout('who'), 1);
%=============================================================================
A = ones(3, 4);
B = 'Nelson';
C = sparse(true);
D = sparse(3i);
save([tempdir(), 'test_who.mat'], 'A', 'B', 'C', 'D')
save([tempdir(), 'test_who.nh5'], 'A', 'B', 'C', 'D')
%=============================================================================
who('-file', [tempdir(), 'test_who.mat'])
c = who('-file', [tempdir(), 'test_who.mat']);
REF = {'A'; 'B'; 'C'; 'D'}
assert_isequal(c, REF);
%=============================================================================
who('-file', [tempdir(), 'test_who.mat'], 'A', 'C')
c = who('-file', [tempdir(), 'test_who.mat'], 'A', 'C');
REF = {'A'; 'C'}
assert_isequal(c, REF);
%=============================================================================
who('-file', [tempdir(), 'test_who.nh5'])
c = who('-file', [tempdir(), 'test_who.nh5']);
REF = {'A'; 'B'; 'C'; 'D'}
assert_isequal(c, REF);
%=============================================================================
who('-file', [tempdir(), 'test_who.nh5'], 'A', 'C')
c = who('-file', [tempdir(), 'test_who.nh5'], 'A', 'C');
REF = {'A'; 'C'}
assert_isequal(c, REF);
%=============================================================================
who()
who('global')
%=============================================================================