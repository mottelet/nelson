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
assert_isequal(nargin('webwrite'), -1);
assert_isequal(nargout('webwrite'), -1);
%=============================================================================
options = weboptions('Timeout', 10);
%=============================================================================
[Y, M, D, H, MN, S] = datevec(now);
datetime = sprintf('%d/%d/%d %d:%d:%d', Y, M, D, H, MN, S);
% hide url to slack
url = char([104 116 116 112 115 58 47 47 104 111 111 107 115 46 115 108 97 99 107 46 99 111 109 47 115 101 114 118 105 99 101 115 47 84 77 82 71 56 82 72 68 50 47 66 77 83 48 76 72 65 65 67 47 81 54 52 97 52 49 84 83 76 104 105 78 71 81 108 100 51 115 76 50 86 109 74 71]);
data = struct('text', ['hello from Nelson ', datetime], 'channel', '#test_webwrite');
R = webwrite(url, data, options);
assert_isequal(R, 'ok');
%=============================================================================
[Y, M, D, H, MN, S] = datevec(now);
datetime = sprintf('%d/%d/%d %d:%d:%d', Y, M, D, H, MN, S);
% hide url to slack
url = char([104 116 116 112 115 58 47 47 104 111 111 107 115 46 115 108 97 99 107 46 99 111 109 47 115 101 114 118 105 99 101 115 47 84 77 82 71 56 82 72 68 50 47 66 77 83 48 76 72 65 65 67 47 81 54 52 97 52 49 84 83 76 104 105 78 71 81 108 100 51 115 76 50 86 109 74 71]);
data = struct('text', ['hello from Nelson ', datetime], 'channel', '#test_webwrite');
R = webwrite(url, jsonencode(data), options);
assert_isequal(R, 'ok');
%=============================================================================
api = 'https://zzxuhwtog6.execute-api.us-east-1.amazonaws.com/mwparticle';
url = [api, '/photon1'];
input = struct('data','on');
userInfo = webwrite(url, input, options);
if contains(fieldnames(userInfo), 'data')
    assert_isequal(userInfo, input);
else
    assert_istrue(contains(userInfo.errorMessage, 'Task timed out after'));
end
%=============================================================================