
#######################################
# Project Settings
#######################################

cmake_minimum_required(VERSION 3.9)
project(GLCD)

find_package (Eigen3 3 REQUIRED)
find_package(OpenMP)

set(BUILD_SHARED_LIBS ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories(
    "${CMAKE_SOURCE_DIR}/Library/"
    ${EIGEN3_INCLUDE_DIR}
)

#######################################
# Project Structure
#######################################
add_subdirectory(Library)
add_subdirectory(Examples)
