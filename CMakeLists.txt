cmake_policy(SET CMP0048 NEW)
project(RemoteDiscHealthMonitor)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

#external projects
add_subdirectory(googletest)
add_subdirectory(QtZeroConf)
#

add_subdirectory(src/agent)
add_subdirectory(src/monitor)
add_subdirectory(tests)
