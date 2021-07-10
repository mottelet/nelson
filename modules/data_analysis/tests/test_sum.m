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
assert_isequal(class(sum(single(3i),'default')), 'single');
assert_isequal(sum(single(3i)), single(3i));
%=============================================================================
assert_isequal(class(sum(single(3i),'double')), 'double');
%=============================================================================
assert_isequal(class(sum(true,'native')), 'logical');
assert_isequal(sum(true,'native'), true);
%=============================================================================
assert_isequal(class(sum(true,'default')), 'double');
assert_isequal(sum(true,'default'), 1);
%=============================================================================
assert_isequal(class(sum(true,'double')), 'double');
assert_isequal(sum(true,'double'), 1);
%=============================================================================
assert_checkerror('sum(''A'')', [_('function') , ' ', 'char', '_sum', ' ',  _('undefined.')])
%=============================================================================
M = [ 8    1    6;
3    5    7;
4    9    2];
R = sum(M);
REF = [  15    15    15];
assert_isequal(R, REF);
%=============================================================================
R = sum(M, 2);
REF = [15; 15; 15];
assert_isequal(R, REF);
%=============================================================================
M = [ 8    1    6;
3    5    7;
4    9    2];
R = sum(M, 4);
REF = M;
assert_isequal(R, REF);
%=============================================================================
M = [10:30:70; 20:30:80; 30:30:90];
R = sum(M);
REF = [60   150   240];
assert_isequal(R, REF);
%=============================================================================
M = [true,false;true,true];
R = sum(M);
REF = [2 1];
assert_isequal(R, REF);
%=============================================================================
M = [1:3:7;2:3:8;3:3:9];
M(:,:,2) = [10:3:16;11:3:17;12:3:18];
R = sum(M, 3);
REF = [    11    17    23;13    19    25;15    21    27];
assert_isequal(R, REF);
%=============================================================================
M = single([12 15 18; 13 16 19; 14 17 20]);
R = sum(M, 2, 'double');
REF = [45;48;51];
assert_isequal(R, REF);
assert_isequal(class(R), 'double');
%=============================================================================
M = uint8([10:30:70;20:30:80;30:30:90]);
R = sum(M, 'native');
REF = uint8([60   150   240]);
assert_isequal(R, REF);
%=============================================================================
M = [10 3 2 4 NaN 30 NaN 20];
R = sum(M, 'omitnan');
REF = 69;
assert_isequal(R, REF);
%=============================================================================
R = sum(zeros(0, 0));
REF = 0;
assert_isequal(R, REF);
%=============================================================================
R = sum(zeros(0, 1));
REF = 0;
assert_isequal(R, REF);
%=============================================================================
R = sum(zeros(3,0,3));
REF =  zeros(1, 0, 3);
assert_isequal(R, REF);
%=============================================================================
R = sum([intmax('uint64'), intmin('uint64'), intmax('uint64')]);
REF = 3.689348814741910e+19;
assert_isapprox(R, REF, eps);
%=============================================================================
A = int32(1:10);
R = sum(A,'native');
REF = int32(55);
assert_isequal(R, REF);
%=============================================================================