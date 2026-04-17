cmake_minimum_required(VERSION 3.10)
project(abcc-version-demo C)

# --- Generate build info from git metadata -----------------------------------
# Uses CMake's own git integration so it works on all platforms.
# If git is unavailable the fallback header (build_info_fallback.h) is used.
set(BUILD_INFO_HEADER "${CMAKE_SOURCE_DIR}/inc/build_info.h")

find_package(Git QUIET)
if(GIT_FOUND)
    add_custom_target(generate_build_info ALL
        COMMAND "${CMAKE_COMMAND}"
            -DGIT_EXECUTABLE=${GIT_EXECUTABLE}
            -DOUTPUT_FILE=${BUILD_INFO_HEADER}
            -DREPO_DIR=${CMAKE_SOURCE_DIR}
            -P "${CMAKE_SOURCE_DIR}/cmake/GenerateBuildInfo.cmake"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        COMMENT "Generating inc/build_info.h"
        VERBATIM
    )
else()
    add_custom_target(generate_build_info ALL
        COMMAND ${CMAKE_COMMAND} -E echo "Skipping build info generation (git not found)"
    )
endif()

# --- Version demo executable -------------------------------------------------
add_executable(version_demo src/main.c)
target_include_directories(version_demo PRIVATE "${CMAKE_SOURCE_DIR}/inc")
add_dependencies(version_demo generate_build_info)
