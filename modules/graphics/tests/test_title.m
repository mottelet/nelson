%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ADV-CLI MODE-->
%=============================================================================
f = figure();
plot((1:10).^2);
t = title('Case number # 42', 'Color', 'm');
assert_isequal(t.Type, 'text');
assert_isequal(t.String, 'Case number # 42');
assert_isequal(t.Color, [1 0 1]);
%=============================================================================