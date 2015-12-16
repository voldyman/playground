cmake_minimum_required(VERSION 2.8)

project(pybindTest C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PYBIND11_PYTHON_VERSION "" CACHE STRING "Python version to use for compiling the example application")
find_package(PythonLibs ${PYBIND11_PYTHON_VERSION} REQUIRED)
find_package(PythonInterp ${PYBIND11_PYTHON_VERSION} REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})

include_directories(deps/pybind11/include/)

add_library(nativefn SHARED
  src/main.cc
)

set_target_properties(nativefn PROPERTIES PREFIX "")
set_target_properties(nativefn PROPERTIES SUFFIX ".so")
set_target_properties(nativefn PROPERTIES COMPILE_FLAGS "-Os")
