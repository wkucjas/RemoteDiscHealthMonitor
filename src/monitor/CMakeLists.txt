
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(monitor
    main.cpp
)

target_link_libraries(monitor
                        PRIVATE
                            Qt::Widgets
)
