cmake_minimum_required(VERSION 3.21)

project(Glenn LANGUAGES CXX C)

add_subdirectory(external)

file(GLOB GLENN_HEADERS include/glenn/*.h)
file(GLOB GLENN_SOURCES source/glenn/*.cpp)
add_library(Glenn STATIC ${GLENN_SOURCES} ${GLENN_HEADERS})
target_link_libraries(Glenn
    PUBLIC glfw
    PUBLIC glad
    INTERFACE glm
    PRIVATE ImGui
    PRIVATE ImGuiBackend
)
target_include_directories(Glenn
    PUBLIC include/
)

option(GLENN_EXAMPLES "Inlucdes examples of Glenn usage" ON)

if (GLENN_EXAMPLES)
    add_subdirectory(examples)
endif()
