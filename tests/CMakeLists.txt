
add_subdirectory(agent)
add_subdirectory(common)
add_subdirectory(monitor)

add_custom_target(RunUnitTests ALL
    COMMAND ctest -C $<CONFIG>
    DEPENDS monitorTests
    DEPENDS agentTests
    DEPENDS commonTests
)
