cmake_minimum_required(VERSION 3.16)
project(TestProject VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    "src/main.cpp"
    "src/fft.cpp"
)

set(LIBRARIES
    "fftw3")

add_executable(TestProject ${SOURCES})

target_include_directories(TestProject
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(TestProject PRIVATE ${LIBRARIES})