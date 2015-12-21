cmake_minimum_required(VERSION 2.8)

project(poco-lib C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(POCO_STATIC ON)

option(ENABLE_ZIP ON)
option(ENABLE_PDF OFF)
option(ENABLE_DATA ON)
option(ENABLE_REDIS OFF)
option(ENABLE_TESTS OFF)
option(ENABLE_NETSSL ON)
option(ENABLE_CRYPTO ON)
option(ENABLE_NETSSL OFF)
option(ENABLE_POCODOC OFF)
OPTION(ENABLE_MONGODB OFF)
option(ENABLE_DATA_ODBC ON)
option(ENABLE_SEVENZIP OFF)
option(ENABLE_CPPPARSER OFF)
option(ENABLE_DATA_MYSQL ON)
option(ENABLE_DATA_SQLITE ON)
option(ENABLE_PAGECOMPILER ON)
option(ENABLE_APACHECONNECTOR OFF)
option(ENABLE_PAGECOMPILER_FILE2PAGE ON)

add_subdirectory(deps/poco-develop)

add_executable(${CMAKE_PROJECT_NAME}
  src/main.cc
)
target_link_libraries(${CMAKE_PROJECT_NAME}
  PocoNet
  PocoFoundation)

add_dependencies(${CMAKE_PROJECT_NAME} PocoNet)
