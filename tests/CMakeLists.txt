add_definitions(
    -fsanitize=address
    -g
    -fno-omit-frame-pointer
)
file(GLOB ${PROJECT_NAME}_TEST_SOURCES
    *.cpp
)
add_executable(test_${PROJECT_NAME}
    ${${PROJECT_NAME}_TEST_SOURCES}
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
)
target_link_libraries(test_${PROJECT_NAME}
    asan
    ${CONAN_LIBS}
)
enable_testing()
add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})