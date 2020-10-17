
find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(monitorTests
    ActiveAgentsListTests.cpp
)

target_include_directories(monitorTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/monitor
)

target_link_libraries(monitorTests
    gmock_main
    Qt::Core
)

add_test(
    NAME monitorTests
    COMMAND monitorTests
)
