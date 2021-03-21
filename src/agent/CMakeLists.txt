
find_package(Qt5 5.15 REQUIRED COMPONENTS Core RemoteObjects)

qt5_generate_repc(REPC ${PROJECT_SOURCE_DIR}/src/common/AgentStatus.rep SOURCE)

ADD_EXECUTABLE( agent
				main.cpp
				IProbe.h
				ISmartReader.h
				SmartReader.h
                Server.h
                Server.cpp
                
                
                DiscStatusCalculator.h
                DiscStatusCalculator.cpp
                IDiskCollector.h
                Disk.h
                Disk.cpp
                SystemUtilitiesFactory.h
                ${REPC}
)

target_include_directories(agent
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(agent
    PRIVATE
        common

        QtZeroConf
        Qt::Core
        Qt::Network
        Qt::RemoteObjects
)

set_target_properties(agent PROPERTIES AUTOMOC TRUE)

if(WIN32)
    find_library(WBEMUUID_LIBRARY wbemuuid
        PATHS "C:/Program Files (x86)/Windows Kits/10/Lib/*/um/x64"
        REQUIRED
    )

    target_sources(agent
        PRIVATE
            windows/WinGeneralAnalyzer.h
            windows/WinGeneralAnalyzer.cpp
            windows/WindowsSmartReader.cpp
            windows/WMICommunication.h
            windows/WMICommunication.cpp
            windows/CMDCommunication.h
            windows/CMDCommunication.cpp
            windows/WinDiskCollector.h
            windows/WinDiskCollector.cpp
            windows/WinSystemUtilitiesFactory.cpp
            windows/WinSmartAnalyzer.h
            windows/WinSmartAnalyzer.cpp
    )

    target_link_libraries(agent
        PRIVATE
            ${WBEMUUID_LIBRARY}
    )
elseif(UNIX AND NOT APPLE)
    target_sources(agent
        PRIVATE
            linux/DmesgParser.cpp
            linux/DmesgParser.h
            linux/IPartitionsManager.h
            linux/LinuxSmartReader.cpp
            linux/LinGeneralAnalyzer.h
            linux/LinGeneralAnalyzer.cpp
            linux/LinSystemUtilitiesFactory.cpp
            linux/LinuxDiskCollector.cpp
            linux/LinuxDiskCollector.h
            linux/LsblkOutputParser.cpp
            linux/LsblkOutputParser.h
            linux/SmartCtlOutputParser.cpp
            linux/SmartCtlOutputParser.h
    )
elseif(APPLE)
    # use SMART reader from linux
    target_sources(agent
        PRIVATE
            linux/DmesgParser.cpp
            linux/DmesgParser.h
            linux/IPartitionsManager.h
            linux/LinuxSmartReader.cpp
            linux/LinGeneralAnalyzer.h
            linux/LinGeneralAnalyzer.cpp
            linux/LinSystemUtilitiesFactory.cpp
            linux/LinuxDiskCollector.cpp
            linux/LinuxDiskCollector.h
            linux/LsblkOutputParser.cpp
            linux/LsblkOutputParser.h
            linux/SmartCtlOutputParser.cpp
            linux/SmartCtlOutputParser.h
    )
else()
    message(FATAL_ERROR "Unsupported system")
endif()
