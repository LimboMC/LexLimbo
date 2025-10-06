add_executable (Limbo 
"glad.c" "lex.c")
set_property(TARGET Limbo PROPERTY CXX_STANDARD 17 C_STANDARD 03)
target_compile_options(Limbo PRIVATE -Wall)
target_include_directories(Limbo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../src 
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glad/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glm
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/raudio/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/STB/include/STBLib
)
target_link_libraries(Limbo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw3.lib
)