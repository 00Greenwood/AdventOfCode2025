# Glob for all source and header files
file(GLOB SOLUTIONS_SOURCES "*.cxx")
file(GLOB SOLUTIONS_HEADERS "*.hxx")

add_library(Solutions ${SOLUTIONS_SOURCES} ${SOLUTIONS_HEADERS})

target_precompile_headers(Solutions PRIVATE precompiled.hxx)

target_include_directories(Solutions PRIVATE     
    "${PROJECT_SOURCE_DIR}/Solutions"
    "${PROJECT_SOURCE_DIR}/Utilities"
)

target_link_libraries(Solutions PUBLIC Utilities)
