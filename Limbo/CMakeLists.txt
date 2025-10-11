cmake_minimum_required(VERSION 3.10)
project(Limbo C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_executable(Limbo
    "glad.c"
    "lex.c"
    "lexcore.c"
)
target_compile_options(Limbo PRIVATE -Wall)
target_include_directories(Limbo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/cglm
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/MiniAudio
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/STB/include/STBLib
)
target_link_libraries(Limbo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw3.lib
)
if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(Limbo PRIVATE /MDd)
    else()
        target_compile_options(Limbo PRIVATE /MD)
    endif()
endif()