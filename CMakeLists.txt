cmake_minimum_required(VERSION 2.8)

project(MATHX_REPL CXX)


# Force out-of-tree builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

# Include headers
include_directories(include)

# Add example folder
add_subdirectory(src)