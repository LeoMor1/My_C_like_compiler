# Exécutable principal
add_executable(my_compiler
  main.c
  lexer/scan.c
  utils.c
)

# Inclure les headers
target_include_directories(my_compiler PRIVATE ${CMAKE_SOURCE_DIR}/include)