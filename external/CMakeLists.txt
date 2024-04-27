include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/glfw
)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG        5bf3eda6da606324999775b88a90ed572202be93 # c
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/glad
)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        1.0.1
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/glm
)

FetchContent_Declare(
  ImGui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        v1.90.5-docking
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/imgui
)

FetchContent_MakeAvailable(glfw glm)

FetchContent_Populate(glad)

file(GLOB GLAD_HEADERS ${glad_SOURCE_DIR}/include/*.h)
file(GLOB GLAD_SOURCES ${glad_SOURCE_DIR}/src/glad.c)
add_library(glad STATIC ${GLAD_SOURCES} ${GLAD_HEADERS})
target_include_directories(glad PUBLIC
  ${glad_SOURCE_DIR}/include/
)

FetchContent_Populate(ImGui)

file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
target_include_directories(ImGui
  PUBLIC imgui
  INTERFACE ${ImGui_SOURCE_DIR}/
)
set_target_properties(ImGui PROPERTIES
  FOLDER "ImGui"
)

file(GLOB IMGUI_BACKEND_HEADERS
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3_loader.h
)
file(GLOB IMGUI_BACKEND_SOURCES
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
add_library(ImGuiBackend STATIC ${IMGUI_BACKEND_SOURCES} ${IMGUI_BACKEND_HEADERS})
target_link_libraries(ImGuiBackend glad glfw ImGui)
set_target_properties(ImGuiBackend PROPERTIES
    FOLDER "ImGui"
)
