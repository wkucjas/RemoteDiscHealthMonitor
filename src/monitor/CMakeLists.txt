
find_package(Qt5 REQUIRED COMPONENTS Quick Network Gui)

qt5_add_resources(QML_RESOURCES
    Qml/resources.qrc
)

add_executable(monitor
    AgentsList.cpp
    AgentsList.hpp
    AgentInformation.cpp
    AgentInformation.hpp
    AgentsExplorer.cpp
    AgentsExplorer.hpp
    AgentsStatusProvider.cpp
    AgentsStatusProvider.hpp
    AgentStatusFetcher.cpp
    AgentStatusFetcher.hpp
    Configuration.cpp
    Configuration.hpp
    IAgentsStatusProvider.hpp
    main.cpp
    ManualAgentsValidator.cpp
    ManualAgentsValidator.hpp
    ${QML_RESOURCES}
)

target_link_libraries(monitor
    PRIVATE
        common

        Qt::Network
        Qt::Quick
        Qt::Gui
        QtZeroConf
)

target_include_directories(monitor
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)

set_target_properties(monitor PROPERTIES AUTOMOC TRUE)
