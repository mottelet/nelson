%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function x = asind(varargin)
    narginchk(1, 1);
    nargoutchk(0, 1);
    x = asin (varargin{1}) .* 180 ./ pi;
end
%=============================================================================
  