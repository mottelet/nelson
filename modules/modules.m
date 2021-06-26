% ============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
% ============================================================================
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
% ============================================================================
modules_list = [
"functions_manager";
"modules_manager";
"engine";
"core";
"localization";
"i18n";
"string";
"debugger";
"error_manager";
"overload";
"function_handle";
"constructors_functions";
"logical";
"types";
"single";
"double";
"data_structures";
"integer";
"operators";
"elementary_functions";
"data_analysis";
"special_functions";
"trigonometric_functions";
"sparse";
"files_folders_functions";
"os_functions";
"json";
"stream_manager";
"file_archiver";
"dynamic_link";
"memory_manager";
"console";
"interpreter";
"time";
"random";
"history_manager";
"help_tools";
"gui";
"help_browser";
"assert_functions";
"tests_manager";
"linear_algebra";
"handle";
"qml_engine";
"com_engine";
"f2c";
"nig";
"text_editor";
"mpi";
"audio";
"sio_client";
"hdf5";
"matio";
"profiler";
"characters_encoding";
"webtools";
"graphics";
"mex";
"ipc";
"statistics";
"validators"
];
% ============================================================================
% optional modules
% ============================================================================
modules_list = [modules_list; "slicot"];
modules_list = [modules_list; "fftw"];
% ============================================================================
% modules sorted for help
% ============================================================================
modules_help_list = [
"engine";
"interpreter";
"core";
"functions_manager";
"debugger";
"profiler";
"error_manager";
"memory_manager";
"modules_manager";
"operators";
"elementary_functions";
"data_analysis";
"special_functions";
"constructors_functions";
"types";
"string";
"single";
"double";
"integer";
"sparse";
"logical";
"data_structures";
"function_handle";
"handle";
"overload";
"dynamic_link";
"f2c";
"os_functions";
"files_folders_functions";
"stream_manager";
"hdf5";
"matio";
"json";
"trigonometric_functions";
"linear_algebra";
"fftw";
"slicot";
"time";
"random";
"assert_functions";
"tests_manager";
"console";
"gui";
"history_manager";
"help_browser";
"help_tools";
"characters_encoding";
"localization";
"i18n";
"qml_engine";
"com_engine";
"nig";
"text_editor";
"mpi";
"audio";
"sio_client";
"file_archiver";
"webtools";
"mex";
"graphics";
"ipc";
"statistics";
"validators"
];
% ============================================================================
