cmake_minimum_required(VERSION 3.20.4)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

project(AdventOfCode2025)

add_executable(AdventOfCode2025 main.cxx)

target_precompile_headers(AdventOfCode2025 PRIVATE precompiled.hxx)

target_include_directories(AdventOfCode2025 PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

add_subdirectory(Solutions)
add_subdirectory(Utilities)

target_link_libraries(AdventOfCode2025 PUBLIC Solutions)

