# Exécutable principal
add_executable(my_compiler
  main.c
)

# Inclure les headers
target_include_directories(my_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)