
find_package(Qt5 5.15 REQUIRED COMPONENTS Core Network)

ADD_EXECUTABLE( agent
				main.cpp
				HealthChecker.h
				HealthChecker.cpp
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
        QtZeroConf
        Qt::Core
        Qt::Network
)

if(WIN32)
    find_library(WBEMUUID_LIBRARY wbemuuid REQUIRED)

    target_sources(agent
        PRIVATE
            windows/WindowsSmartReader.cpp
            windows/WMICommunication.h
            windows/WMICommunication.cpp
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
