%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = [2 4 6 8; 3 5 7 9];
B = 10 * ones(2,4);
R1 = A ./ B;
R2 = rdivide(A, B);
assert_isequal(R1, R2);
REF = [  0.2000,    0.4000,    0.6000,    0.8000;
0.3000,    0.5000,    0.7000,    0.9000];
assert_isapprox(R1, REF);
%=============================================================================
A = [2 4 6 8; 3 5 7 9];
B = 10 * ones(2,4);
R = B ./ A;
REF = [5.0000    2.5000    1.6667    1.2500;
3.3333    2.0000    1.4286    1.1111];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
A = int16(10);
B = int16([3 4 6]);
R = A ./ B;
REF = int16([  3   3   2]);
assert_isequal(R, REF);
%=============================================================================
A = int32(10);
B = int32([3 4 6]);
R = A ./ B;
REF = int32([  3   3   2]);
assert_isequal(R, REF);
%=============================================================================
A = int64(10);
B = int64([3 4 6]);
R = A ./ B;
REF = int64([  3   3   2]);
assert_isequal(R, REF);
%=============================================================================
R = int16(2) ./int16(4);
REF = int16(1);
assert_isequal(R, REF);
%=============================================================================
R = int32(2) ./int32(4);
REF = int32(1);
assert_isequal(R, REF);
%=============================================================================
R = int64(2) ./int64(4);
REF = int64(1);
assert_isequal(R, REF);
%=============================================================================
A = int16([2 4 6 8; 3 5 7 9]);
B = int16(10 * ones(2,4));
R = A ./ B;
REF = int16([0               0               1               1 ;
0               1               1               1  ]);
assert_isequal(R, REF);
%=============================================================================
A = int32([2 4 6 8; 3 5 7 9]);
B = int32(10 * ones(2,4));
R = A ./ B;
REF = int32([0               0               1               1 ;
0               1               1               1  ]);
assert_isequal(R, REF);
%=============================================================================
A = int64([2 4 6 8; 3 5 7 9]);
B = int64(10 * ones(2,4));
R = A ./ B;
REF = int64([0               0               1               1 ;
0               1               1               1  ]);
assert_isequal(R, REF);
%=============================================================================
R = intmax('int16') ./ int16(0);
REF = intmax('int16');
assert_isequal(R, REF);
%=============================================================================
R = intmax('int32') ./ int32(0);
REF = intmax('int32');
assert_isequal(R, REF);
%=============================================================================
R = intmax('int64') ./ int64(0);
REF = intmax('int64');
assert_isequal(R, REF);
%=============================================================================
A = 5;
B = [ 8     1     6;3     5     7;4     9     2];
R = A ./ B;
REF = [ 0.6250    5.0000    0.8333;
1.6667    1.0000    0.7143;
1.2500    0.5556    2.5000];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = 2 ./ [1;2;3];
REF = [ 2; 1; 0.666666666666667];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = 2 ./ [1 2 3];
REF = [ 2  1  0.666666666666667];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = [1 2 3] ./ ones(3, 3);
REF = [ 1     2     3;1     2     3;1     2     3];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = ones(3, 3) ./ [1 2 3];
REF = [ 1.000000000000000   0.500000000000000   0.333333333333333;
1.000000000000000   0.500000000000000   0.333333333333333;
1.000000000000000   0.500000000000000   0.333333333333333];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = [1 2 3; 4 5 6; 7 8 9] ./ [1 2 3];
REF = [1.000000000000000   1.000000000000000   1.000000000000000;
4.000000000000000   2.500000000000000   2.000000000000000;
7.000000000000000   4.000000000000000   3.000000000000000];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = [1 2i 3] ./ ones(3, 3);
REF = [  1.000000000000000 + 0.000000000000000i  0.000000000000000 + 2.000000000000000i  3.000000000000000 + 0.000000000000000i;
1.000000000000000 + 0.000000000000000i  0.000000000000000 + 2.000000000000000i  3.000000000000000 + 0.000000000000000i;
1.000000000000000 + 0.000000000000000i  0.000000000000000 + 2.000000000000000i  3.000000000000000 + 0.000000000000000i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = ones(3, 3) ./ [1 2 3i];
REF = [  1.000000000000000 + 0.000000000000000i  0.500000000000000 + 0.000000000000000i  0.000000000000000 - 0.333333333333333i;
1.000000000000000 + 0.000000000000000i  0.500000000000000 + 0.000000000000000i  0.000000000000000 - 0.333333333333333i;
1.000000000000000 + 0.000000000000000i  0.500000000000000 + 0.000000000000000i  0.000000000000000 - 0.333333333333333i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
