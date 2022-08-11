%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function c = dlgetnelsonlibraries()
  c = {[modulepath(nelsonroot(),'interpreter','bin'), '/libnlsInterpreter']; ...
  [modulepath(nelsonroot(),'i18n','bin'), '/libnlsI18n']; ...
  [modulepath(nelsonroot(),'error_manager','bin'), '/libnlsError_manager']; ...
  [modulepath(nelsonroot(),'types','bin'), '/libnlsTypes']; ...
  [modulepath(nelsonroot(),'validators','bin'), '/libnlsValidators']};
end
%=============================================================================
