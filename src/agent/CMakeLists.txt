
if(WIN32)
    set(system_specific_sources
    			windows/WindowsSmartReader.h
				windows/WindowsSmartReader.cpp
    )
elseif(UNIX AND NOT APPLE)
    set(system_specific_sources
				linux/LinuxSmartReader.h
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
				SmartReaderFactory.h
				SmartReaderFactory.cpp
				${system_specific_sources}
				)
