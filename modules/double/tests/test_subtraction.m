%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = 3;
B = 4;
assert_isequal(A-B, -1);
%=============================================================================
assert_isequal(3 - [], []);
%=============================================================================
assert_isequal([] - 3, []);
%=============================================================================
assert_isequal(3 - ones(3,0), zeros(3, 0));
%=============================================================================
assert_isequal(ones(3,0) - 3, zeros(3, 0));
%=============================================================================
A = [1 2; 3 4];
B = [5 6; 7 8];
R = A - B;
REF = [-4     -4;-4    -4];
assert_isequal(R, REF);
%=============================================================================
A = [1 2; 3 4];
B = 10;
R1 = A - B;
R2 = B - A;
REF1 = [-9, -8; -7, -6];
REF2 = [9, 8; 7, 6];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [0 10; 10 0];
R = A - 20;
REF = [-20   -10;  -10   -20];
assert_isequal(R, REF);
%=============================================================================
A = [10 0; 20 40];
B = [50 90; 20 10];
R1 = A - B;
R2 = B - A;
REF1 = [-40   -90;    0    30];
REF2 = [40   90;    0    -30];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10, 20, 30, 40];
B = [50; 60; 70];
R1 = A - B;
R2 = B - A;
REF1 = [-40   -30   -20   -10;
-50   -40   -30   -20;
-60   -50   -40   -30];
REF2 = [40    30    20    10;
50    40    30    20;
60    50    40    30];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [10; 100];
R1 = A - B;
R2 = B - A;
REF1 = [     0    10    20;   -60   -50   -40];
REF2 = [     0   -10   -20;    60    50    40];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [1 2 3];
R1 = A - B;
R2 = B - A;
REF1 = [     9    18    27;    39    48    57];
REF2 = [    -9    -18    -27;   -39    -48    -57];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
B = [10 20 30; 40 50 60];
A = [1 2 3];
R1 = A - B;
R2 = B - A;
REF1 = [    -9   -18   -27;   -39   -48   -57];
REF2 = [    9   18   27;   39   48   57];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = ones(3, 1);
B = ones(4, 1);
assert_checkerror('A - B', [_('Size mismatch on arguments to arithmetic operator '), '-']);
%=============================================================================
% complex
A = 3;
B = 4i;
assert_isequal(A-B, 3-4i);
%=============================================================================
assert_isequal(3i - [], []);
%=============================================================================
assert_isequal([] - 3i, []);
%=============================================================================
assert_isequal(3i - ones(3,0), zeros(3, 0));
%=============================================================================
assert_isequal(ones(3,0) - 3i, zeros(3, 0));
%=============================================================================
A = [1 2; 3 4] * i;
B = [5 6; 7 8];
R1 = A - B;
R2 = B - A;
REF1 = [    -5.0000+1.0000i    -6.0000+2.0000i;
-7.0000+3.0000i    -8.0000+4.0000i];
REF2 = [   5.0000-1.0000i   6.0000-2.0000i;
7.0000-3.0000i   8.0000-4.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [1 2; 3 4];
B = 10i;
R1 = A - B;
R2 = B - A;
REF1 = [   1.0000-10.0000i   2.0000-10.0000i;
3.0000-10.0000i   4.0000-10.0000i];
REF2 = [  -1.0000+10.0000i  -2.0000+10.0000i;
-3.0000+10.0000i  -4.0000+10.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [0 10; 10 0];
R1 = A - 20i;
R2 = 20i - A;
REF1 = [   0.0000-20.0000i  10.0000-20.0000i;
10.0000-20.0000i   0.0000-20.0000i];
assert_isequal(R1, REF1);
REF2 = [   0.0000+20.0000i -10.0000+20.0000i;
-10.0000+20.0000i   0.0000+20.0000i];
assert_isequal(R2, REF2);
%=============================================================================
A = [10 0; 20 40];
B = [50 90; 20 10];
R1 = A - (B * i);
R2 = (B * i) - A;
REF1 = [  10.0000-50.0000i   0.0000-90.0000i;
20.0000-20.0000i  40.0000-10.0000i];
REF2 = [ -10.0000+50.0000i   0.0000+90.0000i;
-20.0000+20.0000i -40.0000+10.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10, 20, 30, 40];
B = [50; 60; 70] * i;
R1 = A - B;
R2 = B - A;
REF1 = [  10.0000-50.0000i  20.0000-50.0000i  30.0000-50.0000i  40.0000-50.0000i;
10.0000-60.0000i  20.0000-60.0000i  30.0000-60.0000i  40.0000-60.0000i;
10.0000-70.0000i  20.0000-70.0000i  30.0000-70.0000i  40.0000-70.0000i];
REF2 = [ -10.0000+50.0000i -20.0000+50.0000i -30.0000+50.0000i -40.0000+50.0000i;
-10.0000+60.0000i -20.0000+60.0000i -30.0000+60.0000i -40.0000+60.0000i;
-10.0000+70.0000i -20.0000+70.0000i -30.0000+70.0000i -40.0000+70.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [10; 10] * i;
R2 = B - A;
R1 = A - B;
REF2 = [-10.0000+10.0000i -20.0000+10.0000i -30.0000+10.0000i;
-40.0000+10.0000i -50.0000+10.0000i -60.0000+10.0000i];
REF1 = [  10.0000-10.0000i  20.0000-10.0000i  30.0000-10.0000i;
40.0000-10.0000i  50.0000-10.0000i  60.0000-10.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [1 2 3] * i;
R1 = A - B;
R2 = B - A;
REF1 = [  10.0000-1.0000i  20.0000-2.0000i  30.0000-3.0000i;
40.0000-1.0000i  50.0000-2.0000i  60.0000-3.0000i];
REF2 = [ -10.0000+1.0000i -20.0000+2.0000i -30.0000+3.0000i;
-40.0000+1.0000i -50.0000+2.0000i -60.0000+3.0000i];
assert_isequal(R1, REF1);
assert_isequal(R2, REF2);
%=============================================================================
B = [10 20 30; 40 50 60];
A = [1 2 3] * i;
R1 = A - B;
R2 = B - A;
REF1 = [ -10.0000+1.0000i -20.0000+2.0000i -30.0000+3.0000i
-40.0000+1.0000i -50.0000+2.0000i -60.0000+3.0000i];
assert_isequal(R1, REF1);
REF2 = [10.0000-1.0000i  20.0000-2.0000i  30.0000-3.0000i;
40.0000-1.0000i  50.0000-2.0000i  60.0000-3.0000i];
assert_isequal(R2, REF2);
%=============================================================================
