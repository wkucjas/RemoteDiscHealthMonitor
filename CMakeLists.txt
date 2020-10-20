cmake_policy(SET CMP0048 NEW)
project(RemoteDiscHealthMonitor)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)      # when msvc, build gtest with shared crt library
endif()

set(BUILD_SHARED_LIBS ON)

enable_testing()

#external projects
add_subdirectory(googletest)
add_subdirectory(QtZeroConf)
#

add_subdirectory(src/agent)
add_subdirectory(src/monitor)
add_subdirectory(tests)
