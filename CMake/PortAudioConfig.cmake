# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
if(PORTAUDIO_FOUND)
  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # workaround for github CI with catalina
    if(EXISTS "/usr/local/Cellar/portaudio/19.7.0/include")
      set(PORTAUDIO_INCLUDE_DIRS /usr/local/Cellar/portaudio/19.7.0/include)
    elseif(EXISTS "/usr/local/Cellar/portaudio/19.6.0/include")
      set(PORTAUDIO_INCLUDE_DIRS /usr/local/Cellar/portaudio/19.6.0/include)
    endif()

    if(EXISTS "/opt/homebrew/lib/libportaudio.dylib")
      set(PORTAUDIO_LIBRARIES /opt/homebrew/lib/libportaudio.dylib)
    elseif(EXISTS "/usr/local/Cellar/portaudio/19.7.0/lib/libportaudio.dylib")
      set(PORTAUDIO_LIBRARIES
          /usr/local/Cellar/portaudio/19.7.0/lib/libportaudio.dylib)
    elseif(EXISTS "/usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.dylib")
      set(PORTAUDIO_LIBRARIES
          /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.dylib)
    endif()

    message(STATUS "Found portaudio (MacOs): ${PORTAUDIO_LIBRARIES}")
  endif()
endif()
# ==============================================================================
