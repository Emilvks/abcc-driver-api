/*******************************************************************************
** Copyright 2025-present HMS Industrial Networks AB.
** Licensed under the MIT License.
********************************************************************************
*/

#ifndef PROJECT_VERSION_FULL_H
#define PROJECT_VERSION_FULL_H

#include "version.h"

#if defined(__has_include)
   #if __has_include("build_info.h")
      #include "build_info.h"
   #else
      #include "build_info_fallback.h"
   #endif
#else
   #include "build_info_fallback.h"
#endif

#endif /* PROJECT_VERSION_FULL_H */
