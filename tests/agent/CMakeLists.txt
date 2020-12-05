

add_executable(agentTests
    DiscStatusCalculatorTests.cpp
    ${PROJECT_SOURCE_DIR}/src/agent/DiscStatusCalculator.cpp
    IProbeMock.h)

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
