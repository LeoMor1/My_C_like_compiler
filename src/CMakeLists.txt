add_library(utils_lib STATIC 
  utils/utils.c
)
target_include_directories(utils_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)

add_library(lexer_lib STATIC
  lexer/token.c
  lexer/scan.c
  lexer/lexer.c
  lexer/data.c
)
target_include_directories(lexer_lib PRIVATE ${CMAKE_SOURCE_DIR}/include/lexer)
target_link_libraries(lexer_lib PUBLIC utils_lib)

add_library(parser_lib STATIC 
  parser/ast.c
)
target_include_directories(parser_lib PRIVATE ${CMAKE_SOURCE_DIR}/include/parser)
target_link_libraries(parser_lib PUBLIC utils_lib)

add_executable(my_compiler
  main.c
)
target_include_directories(my_compiler PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(my_compiler PRIVATE 
  utils_lib
  lexer_lib
  parser_lib
)