
find_package(Qt5 REQUIRED COMPONENTS Core Test)

add_executable(monitorTests
    ActiveAgentsListTests.cpp
    IAgentsStatusProviderMock.hpp
    ${PROJECT_SOURCE_DIR}/src/monitor/ActiveAgentsList.cpp
    ${PROJECT_SOURCE_DIR}/src/monitor/AgentInformation.cpp
)

target_include_directories(monitorTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/monitor
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(monitorTests
    common
    gmock_main

    Qt::Core
    Qt::Test
)

add_test(
    NAME monitorTests
    COMMAND monitorTests
)
