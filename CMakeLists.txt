cmake_minimum_required(VERSION 2.8)

project(logs CXX C)

include(conanbuildinfo.cmake)
conan_basic_setup()

option(BUILD_TESTS "Build unittests" ON)

add_definitions(
    -Wall
    -Wextra
    -Werror
    --std=c++14
)

include_directories(include)

file(GLOB ${PROJECT_NAME}_HEADERS
    include/logs/*.h
    src/*.h
)

file(GLOB ${PROJECT_NAME}_SOURCES
    src/*.cpp
)

add_library(${PROJECT_NAME}
    ${${PROJECT_NAME}_HEADERS}
    ${${PROJECT_NAME}_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    ${CONAN_LIBS}
)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(DIRECTORY include/logs
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
)
