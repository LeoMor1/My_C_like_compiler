add_executable(unit_tests
    test_utils.c
)

target_link_libraries(unit_tests
    PRIVATE
    utils_lib
    ${CHECK_LIBRARIES}
)

target_include_directories(unit_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include/*
    ${CHECK_INCLUDE_DIRS}
)

add_test(NAME unit_tests COMMAND unit_tests)