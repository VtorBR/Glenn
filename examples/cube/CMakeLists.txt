file(GLOB CUBE_HEADERS include/cube/*.h)
file(GLOB CUBE_SOURCES source/cube/*.cpp)
add_executable(Cube ${CUBE_HEADERS} ${CUBE_SOURCES})
target_link_libraries(Cube
    PRIVATE Glenn
    PRIVATE ImGui
)
target_include_directories(Cube
    PRIVATE include/
)
set_target_properties(Cube PROPERTIES
    FOLDER "Examples"
)
