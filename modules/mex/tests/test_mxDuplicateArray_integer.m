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
if exist('mxDuplicateArray') == 0
  test_dir = [tempdir(), 'mxDuplicateArray_integer'];
  if isdir(test_dir)
    rmdir(test_dir,'s');
  end
  mkdir(test_dir);
  status = copyfile('mxDuplicateArray.c', test_dir);
  assert_istrue(status);
  cd(test_dir);
  mex('mxDuplicateArray.c');
  addpath(pwd())
end
%=============================================================================
REF = int32([1 2]);
R = mxDuplicateArray(REF);
assert_isequal(R, REF);
%=============================================================================
REF = int64([1 2]);
R = mxDuplicateArray(REF);
assert_isequal(R, REF);
%=============================================================================
