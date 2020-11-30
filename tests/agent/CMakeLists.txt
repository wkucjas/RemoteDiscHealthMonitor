

add_executable(agentTests
    DiscStatusCalculatorTests.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/DiscStatusCalculator.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/windows/WinGeneralAnalyzer.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/windows/CMDCommunication.cpp
)

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
