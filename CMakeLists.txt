
#######################################
# Project Settings
#######################################

cmake_minimum_required(VERSION 2.8)
project(GLCD)

find_package (Eigen3 3 REQUIRED)

SET(CMAKE_BUILD_TYPE Release)

SET(BUILD_SHARED_LIBS ON)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#######################################
# Set Compiler Flags
#######################################

SET(COMPILE_FLAGS "-Wall -std=c++11 -Wfatal-errors -fopenmp")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COMPILE_FLAGS}")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMPILE_FLAGS}")

include_directories(
    "${CMAKE_SOURCE_DIR}/Library/"
    ${EIGEN3_INCLUDE_DIR}
)

#######################################
# Project Structure
#######################################
add_subdirectory(Library)
add_subdirectory(Examples)
