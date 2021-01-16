

add_executable(agentTests
    DiscStatusCalculatorTests.cpp
    DmesgParserTests.cpp
    LsblkOutputParserTests.cpp
    SmartCtlOutputParserTests.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/Disk.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/DiscStatusCalculator.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/linux/DmesgParser.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/linux/LsblkOutputParser.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/linux/SmartCtlOutputParser.cpp
    IPartitionsManagerMock.h
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
