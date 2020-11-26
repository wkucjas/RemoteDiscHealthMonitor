
add_subdirectory(monitor)

add_custom_target(RunUnitTests ALL
    COMMAND ctest -C $<CONFIG>
    DEPENDS monitorTests
)
