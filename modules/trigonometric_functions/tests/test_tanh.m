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
assert_isequal(nargin('tanh'), 1);
assert_isequal(nargout('tanh'), 1);
%=============================================================================
assert_isequal(tanh(NaN), NaN);
assert_isequal(tanh(-NaN), NaN);
assert_isequal(tanh(Inf), 1);
assert_isequal(tanh(-Inf), -1);
%=============================================================================
v = [1.   0.8660254   0.7071068   0.5   0.   0.  -0.5  -0.7071068  -0.8660254  -1];
r = tanh(v);
ref = [0.7616     0.6993     0.6089     0.4621     0.0000     0.0000    -0.4621    -0.6089    -0.6993    -0.7616];
assert_isapprox(r, ref, 1e-4);
%=============================================================================
x = tanh(0i);
ref = 0;
assert_isequal(x, ref);
assert_isequal(tanh(0), 0);
assert_isequal(tanh(-0), 0);
%=============================================================================
X = tanh(zeros(3, 3, 3));
REF = zeros(3, 3, 3);
assert_isequal(X, REF);
%=============================================================================
S = sparse(zeros(3, 3));
X = tanh(S);
REF = sparse(zeros(3, 3));
assert_isequal(X, REF);
%=============================================================================
assert_isequal(tanh([]), []);
%=============================================================================
assert_checkerror('tanh(''a'')', [_('Undefined function ''tanh'' for input arguments of type '''), class('a'), '''.']);
%=============================================================================