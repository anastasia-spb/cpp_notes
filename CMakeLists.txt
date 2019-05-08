cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and supported languages
set(PROJECT_NAME "Interview")
project(${PROJECT_NAME} CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

file(GLOB PROJ_SOURCES
    "src/*.hpp"
    "src/*.cpp"
)

# Define an executable
add_executable(${PROJECT_NAME}
    ${PROJ_SOURCES})