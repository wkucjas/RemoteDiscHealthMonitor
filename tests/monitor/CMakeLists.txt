
find_package(Qt5 REQUIRED COMPONENTS Core Test)

add_executable(monitorTests
    ActiveAgentsListTests.cpp
    ${PROJECT_SOURCE_DIR}/src/monitor/ActiveAgentsList.cpp
    ${PROJECT_SOURCE_DIR}/src/monitor/AgentInformation.cpp
)

target_include_directories(monitorTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/monitor
)

target_link_libraries(monitorTests
    gmock_main
    Qt::Core
    Qt::Test
)

add_test(
    NAME monitorTests
    COMMAND monitorTests
)
