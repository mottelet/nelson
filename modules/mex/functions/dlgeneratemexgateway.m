%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function dlgeneratemexgateway(destinationdir, functionname, interleavedcomplex)
  if ~isdir(destinationdir)
    error(_('Invalid directory.'));
  end
  if ~ischar(functionname)
    error(_('Wrong type for argument #2: string expected.'));
  end
  txt = template(functionname, interleavedcomplex);
  filewrite([destinationdir, '/mexGateway.c'], txt);
end
%=============================================================================
function txt = template(functionname, interleavedcomplex)
  txt = {'//============================================================================='};
  txt = [txt; '// Copyright (c) 2020 - Present Allan CORNET (Nelson)'];
  txt = [txt; '//'];
  txt = [txt; '// Redistribution and use in source and binary forms, with or without'];
  txt = [txt; '// modification, are permitted provided that the following conditions are met:'];
  txt = [txt; '//'];
  txt = [txt; '// Redistributions of source code must retain the above copyright notice, this'];
  txt = [txt; '// list of conditions and the following disclaimer. Redistributions in binary'];
  txt = [txt; '// form must reproduce the above copyright notice, this list of conditions and'];
  txt = [txt; '// the following disclaimer in the documentation and/or other materials'];
  txt = [txt; '// provided with the distribution. Neither the name of the nor the names of'];
  txt = [txt; '// its contributors may be used to endorse or promote products derived from'];
  txt = [txt; '// this software without specific prior written permission.'];
  txt = [txt; '//'];
  txt = [txt; '// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"'];
  txt = [txt; '// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE'];
  txt = [txt; '// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE'];
  txt = [txt; '// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE'];
  txt = [txt; '// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR'];
  txt = [txt; '// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF'];
  txt = [txt; '// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS'];
  txt = [txt; '// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN'];
  txt = [txt; '// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)'];
  txt = [txt; '// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE'];
  txt = [txt; '// POSSIBILITY OF SUCH DAMAGE.'];
  txt = [txt; '//============================================================================='];
  txt = [txt; '// generated by dlgeneratemexgateway'];
  txt = [txt; '//============================================================================='];
  txt = [txt; '#include <string.h>'];
  txt = [txt; '#include "mex.h"'];
  txt = [txt; '//============================================================================='];
  txt = [txt; '#define BUFFER_LENGTH_NAME 4096'];
  txt = [txt; '//============================================================================='];
  txt = [txt; 'bool _isLocked = false;'];
  txt = [txt; 'mex_exit_fn _exitFcn = NULL;'];
  txt = [txt; 'char functionName[BUFFER_LENGTH_NAME] = "', functionname, '";'];
  txt = [txt; '//============================================================================='];
  txt = [txt; 'const char* mexFunctionName() {return "', functionname, '";}'];
  txt = [txt; 'void mexClearAtExit() {if (_exitFcn && !_isLocked) {_exitFcn();}}'];
  txt = [txt; 'void mexLock(void) {_isLocked = true;}'];
  txt = [txt; 'void mexUnlock(void) {_isLocked = false;}'];
  txt = [txt; 'bool mexIsLocked(void) {return _isLocked;}'];
  txt = [txt; 'int mexAtExit(mex_exit_fn exit_fcn) {_exitFcn = exit_fcn; return 0;}'];
  txt = [txt; '//============================================================================='];
  txt = [txt; 'void mexfilerequiredapiversion(unsigned int* built_by_rel, unsigned int* target_api_ver)'];
  txt = [txt; '{'];
  txt = [txt; '*built_by_rel = 0x0000a;'];
  if interleavedcomplex
    txt = [txt; '*target_api_ver = MX_CURRENT_API_VER;'];
  else
    txt = [txt; '*target_api_ver = MX_LAST_SEPARATE_COMPLEX_VER;'];
  end
  txt = [txt; '}'];
  txt = [txt; '//============================================================================='];
end
%=============================================================================
