# Glob for all source and header files
file(GLOB UTILITIES_SOURCES "*.cxx")
file(GLOB UTILITIES_HEADERS "*.hxx")

add_library(Utilities ${UTILITIES_SOURCES} ${UTILITIES_HEADERS})

target_precompile_headers(Utilities PRIVATE precompiled.hxx)

target_include_directories(Utilities PRIVATE .)

# Create a macro for accessing the directory of input files.
target_compile_definitions(Utilities PUBLIC INPUTS_DIR="${CMAKE_SOURCE_DIR}/Inputs")
