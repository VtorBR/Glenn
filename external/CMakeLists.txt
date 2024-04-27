include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/external/glfw
)

FetchContent_MakeAvailable(glfw)
