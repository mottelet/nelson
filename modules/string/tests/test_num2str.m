%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = int64([1 3 4; 4 5 600]);
R = num2str(A);
REF = ['1    3    4'; '4    5  600'];
assert_isequal(R, REF);
%=============================================================================
A = int64([10 3000 4]);
R = num2str(A);
REF = '10  3000     4';
assert_isequal(R, REF);
%=============================================================================
A = int64([4 50 600]);
R = num2str(A);
REF = '4   50  600';
assert_isequal(R, REF);
%=============================================================================
A = int64([10 3000 4; 4 50 600]);
R = num2str(A);
REF = [    '10  3000     4';
' 4    50   600'];
assert_isequal(R, REF);
%=============================================================================
A = int64(eye(2, 2) * diag([-1 1]));
R = num2str(A);
REF = ['-1  0'; ' 0  1'];
assert_isequal(R, REF);
%=============================================================================
R = num2str(int64(1e17+10), 1);
REF = '100000000000000016';
assert_isequal(R, REF)
%=============================================================================
R = num2str([true false true]);
REF = '1  0  1';
assert_isequal(R, REF);
%=============================================================================
A = [true, false; false, true];
R = num2str(A);
REF = ['1  0'; '0  1'];
assert_isequal(R, REF);
%=============================================================================
A = [true, false; false, true];
R = num2str(A, 3);
REF = ['1         0';'0         1'];
assert_isequal(R, REF);
%=============================================================================
A = [true, false; false, true];
R = num2str(A, -5);
REF = ['1 0'; '0 1'];
assert_isequal(R, REF);
%=============================================================================
A = [true, false; false, true];
R = num2str(A, '%4d');
REF = ['1   0'; '0   1'];
assert_isequal(R, REF);
%=============================================================================
R = num2str([]);
REF = char([]);
assert_isequal(R, REF);
%=============================================================================
R = num2str(123);
REF = '123';
assert_isequal(R, REF);
%=============================================================================
R = num2str(1.23);
REF = '1.23';
assert_isequal(R, REF);
%=============================================================================
R = num2str(123.456, 4);
REF = '123.5';
assert_isequal(R, REF);
%=============================================================================
R = num2str('hello');
REF = 'hello';
assert_isequal(R, REF);
%=============================================================================
R = num2str(eye(3,3));
REF = [    '1  0  0';    '0  1  0';    '0  0  1'];
assert_isequal(R, REF)
%=============================================================================
R = num2str(1e15);
REF = '1000000000000000';
assert_isequal(R, REF)
%=============================================================================
R = num2str(1000000000000001);
REF = '1000000000000001';
assert_isequal(R, REF)
%=============================================================================
R = num2str(1e16);
REF = '1e+16';
assert_isequal(R, REF)
%=============================================================================
R = num2str(9999999999999999.99);
REF = '1e+16';
assert_isequal(R, REF)
%=============================================================================
R = num2str(2.4e9, 15);
REF = '2400000000';
assert_isequal(R, REF);
%=============================================================================
R = num2str(pi, 2);
REF = '3.1';
assert_isequal(R, REF);
%=============================================================================
R = num2str([pi; pi; pi], 2);
REF = ['3.1';'3.1';'3.1'];
assert_isequal(R, REF);
%=============================================================================
R = num2str(complex(3*pi, 2*pi));
REF = '9.42478+6.28319i';
assert_isequal(R, REF);
%=============================================================================
R = num2str(eye(1,2)*pi + i);
REF = '3.1416+1i                     0+1i';
assert_isequal(R, REF);
%=============================================================================
R = num2str(eye(3,3)*pi + i);
REF = ['3.1416+1i                     0+1i                     0+1i';
'     0+1i                3.1416+1i                     0+1i';
'     0+1i                     0+1i                3.1416+1i'];
assert_isequal(R, REF)
%=============================================================================
R = num2str(eye(1, 3) * pi + i, 1);
REF =  '3+1i             0+1i             0+1i';
assert_isequal(R, REF)
%=============================================================================
R = num2str(eye(3, 3) * pi + i, 2);
REF = ['3.1+1i               0+1i               0+1i';
'  0+1i             3.1+1i               0+1i';
'  0+1i               0+1i             3.1+1i'];
assert_isequal(R, REF)
%=============================================================================
R = num2str(1.234 + 27.3i);
REF = '1.234+27.3i';
assert_isequal(R, REF);
%=============================================================================
R = num2str(complex(1e18,4));
REF = '1e+18+4i';
assert_isequal(R, REF)
%=============================================================================
R = num2str(complex(pi, -pi/2), "-%3.f");
REF = '-  3--2i';
assert_isequal(R, REF);
%=============================================================================
R = num2str(ones(3, 3) * pi + i, "%3.f");
REF = ['3+1i  3+1i  3+1i';
'3+1i  3+1i  3+1i';
'3+1i  3+1i  3+1i'];
assert_isequal(R, REF);
%=============================================================================
R = num2str(ones(3, 3) * pi + i, "%13.4f");
REF = ['3.1416+1.0000i       3.1416+1.0000i       3.1416+1.0000i';
'3.1416+1.0000i       3.1416+1.0000i       3.1416+1.0000i';
'3.1416+1.0000i       3.1416+1.0000i       3.1416+1.0000i'];
assert_isequal(R, REF);
%=============================================================================
R = num2str(eye(3,3)+i);
REF = ['1+1i   0+1i   0+1i';'0+1i   1+1i   0+1i'; '0+1i   0+1i   1+1i'];
assert_isequal(R, REF)
%=============================================================================
A = reshape([1:6], [1 2 3]);
R = num2str(A);
REF = '1  2  3  4  5  6';
assert_isequal(R, REF)
%=============================================================================
A = [1 2 3; 4 5 6];
R = num2str(A, '%.2f');
REF = [ '1.002.003.00';'4.005.006.00'];
assert_isequal(R, REF);
%=============================================================================
R = num2str([1, 1.34; 3, 3.56], '%5.1f');
REF = ['1.0  1.3'; '3.0  3.6'];
assert_isequal(R, REF);
%=============================================================================
R = num2str([2.1, 1e23, 3]);
REF = '2.1  9.999999999999999e+22                      3';
assert_isequal(R, REF);
%=============================================================================
R = num2str([2.1, 1e23, 3]);
REF = '2.1  9.999999999999999e+22                      3';
assert_isequal(R, REF);
%=============================================================================
R = num2str([2.1, 1e23, pi]);
REF =  '2.1  9.999999999999999e+22      3.141592653589793';
assert_isequal(R, REF);
%=============================================================================
R = num2str([2.1, NaN, pi]);
REF = '2.1         NaN      3.1416';
assert_isequal(R, REF);
%=============================================================================
R = num2str([-Inf, NaN, pi]);
REF = '-Inf         NaN      3.1416';
assert_isequal(R, REF);
%=============================================================================
A = [ 0.0975    0.9575    0.9706;
0.2785    0.9649    0.9572;
0.5469    0.1576    0.4854];
R = num2str(A, 2);
REF = ['0.098     0.96     0.97'; ' 0.28     0.96     0.96'; ' 0.55     0.16     0.49'];
assert_isequal(R, REF);
%=============================================================================
R = num2str(eye(3,3)*1000);
REF = ['1000     0     0';
'   0  1000     0';
'   0     0  1000'];
assert_isequal(R, REF)
%=============================================================================
R = num2str(eye(3,3)*pi, 2);
REF = ['3.1        0        0';
'  0      3.1        0';
'  0        0      3.1'];
assert_isequal(R, REF)
%=============================================================================
S = sparse([    0.8003    0.9157;
0.1419    0.7922;
0.4218    0.9595]);
R = num2str(S);
REF = ['0.8003      0.9157';
'0.1419      0.7922';
'0.4218      0.9595'];
assert_isequal(R, REF)
%=============================================================================
A = [ 0.0975    0.9575    0.9706;
0.2785    0.9649    0.9572;
0.5469    0.1576    0.4854];
R = num2str(A);
REF = ['0.0975      0.9575      0.9706';
'0.2785      0.9649      0.9572';
'0.5469      0.1576      0.4854'];
assert_isequal(R, REF);
%=============================================================================
R = num2str([1, 1.34; 3, 3.56]);
REF = ['1        1.34';'3        3.56'];
assert_isequal(R, REF);
%=============================================================================
assert_checkerror('R = num2str ([65 66 67], ''%44'')', _('Wrong format string.'))
%=============================================================================
