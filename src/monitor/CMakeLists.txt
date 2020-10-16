
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(monitor
    AgentsEnumerator.cpp
    AgentsEnumerator.hpp
    main.cpp
)

target_link_libraries(monitor
    PRIVATE
        Qt::Widgets
)
