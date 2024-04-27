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

FetchContent_MakeAvailable(glfw)

FetchContent_Populate(glad)

file(GLOB GLAD_HEADERS ${glad_SOURCE_DIR}/include/*.h)
file(GLOB GLAD_SOURCES ${glad_SOURCE_DIR}/src/glad.c)
add_library(glad STATIC ${GLAD_SOURCES} ${GLAD_HEADERS})
target_include_directories(glad PUBLIC
  ${glad_SOURCE_DIR}/include/
)
