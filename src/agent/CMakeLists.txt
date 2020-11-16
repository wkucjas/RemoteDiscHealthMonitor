
find_package(Qt5 5.15 REQUIRED COMPONENTS Core Network)

ADD_EXECUTABLE( agent
				main.cpp
				IProbe.h
				ISmartReader.h
				SmartReader.h
                Server.h
                Server.cpp
                )

target_include_directories(agent
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(agent
    PRIVATE
        common

        QtZeroConf
        Qt::Core
        Qt::Network
)

set_target_properties(agent PROPERTIES AUTOMOC TRUE)

if(WIN32)
    find_library(WBEMUUID_LIBRARY wbemuuid REQUIRED)

    target_sources(agent
        PRIVATE
            windows/WinGeneralAnalyzer.h
            windows/WinGeneralAnalyzer.cpp
            windows/WinSmartAnalyzer.h
            windows/WinSmartAnalyzer.cpp
            windows/WindowsSmartReader.cpp
            windows/WMICommunication.h
            windows/WMICommunication.cpp
            windows/CMDCommunication.h
            windows/CMDCommunication.cpp
    )

    target_link_libraries(agent
        PRIVATE
            ${WBEMUUID_LIBRARY}
    )
elseif(UNIX AND NOT APPLE)
    target_sources(agent
        PRIVATE
            linux/LinuxSmartReader.cpp
    )
else()
    message(FATAL_ERROR "Unsupported system")
endif()
