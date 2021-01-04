
find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(common OBJECT
    constants.hpp
    GeneralHealth.h
    ProtocolVersion.h
    OutputParsersUtils.cpp
    OutputParsersUtils.h
    SmartData.cpp
    SmartData.h
    GeneralHealth.cpp)

target_include_directories(common
    PUBLIC ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(common
    PUBLIC
        Qt::Core
)

set_target_properties(common PROPERTIES AUTOMOC TRUE)
