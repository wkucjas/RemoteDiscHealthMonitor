
find_package(Qt5 5.15 REQUIRED COMPONENTS Core Network)

if(WIN32)
    set(system_specific_sources
				windows/WindowsSmartReader.cpp
                windows/WMICommunication.h
				windows/WMICommunication.cpp
    )
elseif(UNIX AND NOT APPLE)
    set(system_specific_sources
				linux/LinuxSmartReader.cpp
    )
else()
    message(FATAL_ERROR "Unsupported system")
endif()

ADD_EXECUTABLE( agent
				main.cpp
				HealthChecker.h
				HealthChecker.cpp
				ISmartReader.h
				SmartReader.h
				${system_specific_sources}
)

target_include_directories(agent
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(agent
    PRIVATE
        QtZeroConf
        Qt::Core
        Qt::Network
        wbemuuid
)
