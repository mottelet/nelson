%=============================================================================
% Copyright (c) 2018 Allan CORNET (Nelson)
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
r = nmm('list');
assert_isequal(class(r), 'struct');
needToRestore = any(contains(fieldnames(r), 'module_skeleton_basic'));
if isempty(needToRestore)
    needToRestore = false;
end
if needToRestore
    nmm('uninstall', 'module_skeleton_basic')
end
%=============================================================================
nmm('install', 'https://github.com/Nelson-numerical-software/module_skeleton_basic.git#v3.0.0');
r = nmm('list');
r = any(contains(fieldnames(r), 'module_skeleton_basic'));
assert_istrue(r);
assert_istrue(ismodule('module_skeleton_basic'));
%=============================================================================
nmm('load', 'module_skeleton_basic');
assert_istrue(ismodule('module_skeleton_basic'));
r = nmm('list');
assert_istrue(isstruct(r.module_skeleton_basic));
assert_istrue(isdir(r.module_skeleton_basic.path));
assert_istrue(r.module_skeleton_basic.load);
%=============================================================================
R = nmm('autoload', 'module_skeleton_basic');
assert_istrue(R);
%=============================================================================
nmm('autoload', 'module_skeleton_basic', true);
r = nmm('list');
assert_istrue(r.module_skeleton_basic.load);
R = nmm('autoload', 'module_skeleton_basic');
assert_istrue(R);
%=============================================================================
filename = nmm('package','module_skeleton_basic', tempdir());
assert_istrue(isfile(filename));
%=============================================================================
nmm('uninstall','module_skeleton_basic');
r = nmm('list');
r = contains(fieldnames(r), 'module_skeleton_basic');
if isempty(r)
  r = false;
end
assert_isfalse(r);
%=============================================================================
nmm('install', [modulepath('modules_manager'), '/tests/module_skeleton_basic-all-3.0.0.nmz']);
r = nmm('list');
r = any(contains(fieldnames(r), 'module_skeleton_basic'));
assert_istrue(r);
nmm('uninstall','module_skeleton_basic');
r = nmm('list');
r = contains(fieldnames(r), 'module_skeleton_basic');
if isempty(r)
  r = false;
end
assert_isfalse(r);
%=============================================================================
if needToRestore
  nmm('install', 'https://github.com/Nelson-numerical-software/module_skeleton_basic.git#v3.0.0');
end
%=============================================================================