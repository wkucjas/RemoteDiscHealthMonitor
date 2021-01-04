

add_executable(agentTests
    DiscStatusCalculatorTests.cpp
    LsblkOutputParserTests.cpp
    SmartCtlOutputParserTests.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/DiscStatusCalculator.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/linux/LsblkOutputParser.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/linux/SmartCtlOutputParser.cpp
    IProbeMock.h
    DiskMock.h)

target_include_directories(agentTests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src/agent
)

target_link_libraries(agentTests
    common
    gmock_main
)

add_test(
    NAME agentTests
    COMMAND agentTests
)
