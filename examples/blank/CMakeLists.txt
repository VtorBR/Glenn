file(GLOB BLANK_HEADERS include/blank/*.h)
file(GLOB BLANK_SOURCES source/blank/*.cpp)
add_executable(Blank ${BLANK_SOURCES} ${BLANK_HEADERS})
target_link_libraries(Blank Glenn)

target_include_directories(Blank
    PRIVATE include/
)
