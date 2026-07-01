# Trouve Check
find_package(PkgConfig REQUIRED)
pkg_check_modules(CHECK REQUIRED check)

find_program(GCOV_PATH gcov)
find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_files DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(units)

add_subdirectory(integration)

add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/coverage
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage

    COMMAND ${LCOV_PATH} --zerocounters --directory ${CMAKE_BINARY_DIR}

    # Capture "baseline" : tous les fichiers instrumentés, avant exécution
    COMMAND ${LCOV_PATH} --capture --initial --directory ${CMAKE_BINARY_DIR}
            --output-file ${CMAKE_BINARY_DIR}/coverage_base.info
            --ignore-errors mismatch,unused

    COMMAND ctest --output-on-failure

    # Capture des données réellement exécutées
    COMMAND ${LCOV_PATH} --capture --directory ${CMAKE_BINARY_DIR} 
            --output-file ${CMAKE_BINARY_DIR}/coverage_run.info
            --ignore-errors mismatch,unused

    # Fusion baseline + exécution réelle
    COMMAND ${LCOV_PATH} --add-tracefile ${CMAKE_BINARY_DIR}/coverage_base.info
            --add-tracefile ${CMAKE_BINARY_DIR}/coverage_run.info
            --output-file ${CMAKE_BINARY_DIR}/coverage_raw.info
            --ignore-errors unused

    # Filtrage : uniquement ton code source
    COMMAND ${LCOV_PATH} --extract ${CMAKE_BINARY_DIR}/coverage_raw.info
            '${CMAKE_SOURCE_DIR}/src/*'
            '${CMAKE_SOURCE_DIR}/include/*'
            --output-file ${CMAKE_BINARY_DIR}/coverage_extracted.info
            --ignore-errors unused

    # Retirer main.c
    COMMAND ${LCOV_PATH} --remove ${CMAKE_BINARY_DIR}/coverage_extracted.info
            '${CMAKE_SOURCE_DIR}/src/main.c'
            --output-file ${CMAKE_BINARY_DIR}/coverage.info
            --ignore-errors unused

    COMMAND ${GENHTML_PATH} ${CMAKE_BINARY_DIR}/coverage.info 
            --output-directory ${CMAKE_BINARY_DIR}/coverage

    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Génération du rapport de couverture de code"
)