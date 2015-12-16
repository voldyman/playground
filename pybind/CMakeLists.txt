cmake_minimum_required(VERSION 2.8)

project(pybindTest C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# begin pythind11 requirements
set(PYBIND11_PYTHON_VERSION "" CACHE STRING "Python version to use for compiling the example application")
find_package(PythonLibs ${PYBIND11_PYTHON_VERSION} REQUIRED)
find_package(PythonInterp ${PYBIND11_PYTHON_VERSION} REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})

# end  pybind11
include_directories(deps/pybind11/include/)

function(build_module module_name)
  add_library(${module_name} SHARED
    ${ARGN}
  )
  set_target_properties(${module_name} PROPERTIES PREFIX "")
  set_target_properties(${module_name} PROPERTIES SUFFIX ".so")
  set_target_properties(${module_name} PROPERTIES COMPILE_FLAGS "-Os")
  
endfunction()

build_module(nativefn
  src/nativefn.cc
)

# begin gtkmm requirements
INCLUDE(FindPkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

include_directories(${GTKMM_INCLUDE_DIRS})

build_module(gui
  src/gtk-gui.cc
)

link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(gui ${GTKMM_LIBRARIES})
# end gtkmm requirements

