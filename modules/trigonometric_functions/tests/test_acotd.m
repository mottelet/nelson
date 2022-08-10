%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('acotd'), -1);
assert_isequal(nargout('acotd'), 1);
%=============================================================================
R = acotd([0 20 Inf]);
REF = [90.0000, 2.8624,0];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = acotd(1+2i);
REF =  13.2825 -23.0535i;
assert_isapprox(R, REF, 1e-4);
%=============================================================================

