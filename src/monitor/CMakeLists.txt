
find_package(Qt5 REQUIRED COMPONENTS Quick Network Gui)

qt5_add_resources(QML_RESOURCES
                    Qml/resources.qrc
)

add_executable(monitor
    ActiveAgentsList.cpp
    ActiveAgentsList.hpp
    AgentInformation.cpp
    AgentInformation.hpp
    AgentsExplorer.cpp
    AgentsExplorer.hpp
    main.cpp
    ${QML_RESOURCES}
)

target_link_libraries(monitor
    PRIVATE
        Qt::Network
        Qt::Quick
        Qt::Gui
        QtZeroConf
)

target_include_directories(monitor
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

set_target_properties(monitor PROPERTIES AUTOMOC TRUE)
