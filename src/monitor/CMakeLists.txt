
find_package(Qt5 REQUIRED COMPONENTS Widgets Network)

add_executable(monitor
    ActiveAgentsList.cpp
    ActiveAgentsList.hpp
    AgentInformation.cpp
    AgentInformation.hpp
    AgentsExplorer.cpp
    AgentsExplorer.hpp
    main.cpp
)

target_link_libraries(monitor
    PRIVATE
        Qt::Widgets
        Qt::Network
        QtZeroConf
)

target_include_directories(monitor
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

set_target_properties(monitor PROPERTIES AUTOMOC TRUE)
