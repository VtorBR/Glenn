cmake_minimum_required(VERSION 3.21)

project(Glenn LANGUAGES CXX C)

add_subdirectory(external)

file(GLOB GLENN_HEADERS include/glenn/*.h)
file(GLOB GLENN_SOURCES source/glenn/*.cpp)
add_library(Glenn STATIC ${GLENN_SOURCES} ${GLENN_HEADERS})
target_link_libraries(Glenn glfw glad ImGui ImGuiBackend)
target_include_directories(Glenn PUBLIC
    include/
)

add_subdirectory(examples)
