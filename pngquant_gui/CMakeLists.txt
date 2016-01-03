cmake_minimum_required(VERSION 2.6)
project(pngquant-gui)

add_subdirectory(deps)

## Link libraries
find_package(Threads REQUIRED)

include_directories(deps/)

add_executable(pngquant-gui
  src/main.cc
)

target_link_libraries(pngquant-gui ${CMAKE_THREAD_LIBS_INIT} libpngquant)

