add_executable(unit_tests
    test_main.c
    test_utils.c
    test_lexer.c
)

target_link_libraries(unit_tests
    PRIVATE
    utils_lib
    lexer_lib
    ${CHECK_LIBRARIES}
)

target_include_directories(unit_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CHECK_INCLUDE_DIRS}
)

add_test(NAME unit_tests COMMAND unit_tests)

set_tests_properties(unit_tests PROPERTIES
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
)