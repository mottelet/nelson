%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
rng('default');
r = rng();
assert_isequal(class(r), 'struct');
assert_isequal(fieldnames(r), {'Type'; 'Seed'; 'State'});
assert_isequal(size(r), [1 1]);
assert_isequal(r.Type, 'twister');
assert_isequal(r.Seed, uint32(0));
assert_isequal(size(r.State), [624, 1]);
assert_isequal(class(r.State), 'uint32');
%=============================================================================
res = rand(3, 3);
ref = [      0.8147      0.9134      0.2785;
0.9058      0.6324      0.5469;
0.1270      0.0975      0.9575];
assert_isapprox(res, ref, 1e-4);
%=============================================================================
res = rand(3, 3);
ref = [ 0.9649      0.9572      0.1419;
0.1576      0.4854      0.4218;
0.9706      0.8003      0.9157];
assert_isapprox(res, ref, 1e-4);
%=============================================================================
res = rand(3, 3);
ref = [0.7922      0.0357      0.6787;
0.9595      0.8491      0.7577;
0.6557      0.9340      0.7431];
assert_isapprox(res, ref, 1e-4);
%=============================================================================
r = rng();
%=============================================================================
R1 = rand(3, 3);
ref = [0.3922      0.7060      0.0462;
0.6555      0.0318      0.0971;
0.1712      0.2769      0.8235];
assert_isapprox(R1, ref, 1e-4);
%=============================================================================
rng('default');
rng(r);
%=============================================================================
R2 = rand(3, 3);
ref = [     0.3922      0.7060      0.0462;
0.6555      0.0318      0.0971;
0.1712      0.2769      0.8235];
assert_isapprox(R2, ref, 1e-4);
assert_isequal(R1, R2);
%=============================================================================
rng('default')
rng(5489)
R2 = rand(3, 3);
ref = [0.8147     0.9134     0.2785;
0.9058     0.6324     0.5469;
0.1270     0.0975     0.9575 ];
assert_isapprox(R2, ref, 1e-4);
%=============================================================================
R = rand([0 0]);
REF = [];
assert_isequal(R, REF);
%=============================================================================
R = rand([0 3]);
REF = zeros(0, 3);
assert_isequal(R, REF);
%=============================================================================
