
cmake_policy(SET CMP0048 NEW)
project(RemoteDiscHealthMonitor)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)      # when msvc, build gtest with shared crt library
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(BUILD_SHARED_LIBS OFF)
else()
    set(BUILD_SHARED_LIBS ON)
endif()

enable_testing()

#external projects
add_subdirectory(googletest)
add_subdirectory(QtZeroConf)
#

add_subdirectory(src/common)
add_subdirectory(src/agent)
add_subdirectory(src/monitor)
add_subdirectory(tests)
