cmake_minimum_required(VERSION 3.16)
project(test_project)

# cmake --build build && cmake build

set(SOURCES
    src/main.cpp
)

add_executable(test_project ${SOURCES})

target_include_directories(test_project
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include)

target_link_directories(test_project
    PRIVATE
        ${PROJECT_SOURCE_DIR}/lib)