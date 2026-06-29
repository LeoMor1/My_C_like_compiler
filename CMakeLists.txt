cmake_minimum_required(VERSION 3.10)
project(My_C_like_compiler C)

# Configuration du compilateur
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)

set_target_properties(my_compiler PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)