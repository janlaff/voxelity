cmake_minimum_required(VERSION 3.16)
project(Voxelity)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(
        SOURCE_FILES
        src/main.cpp
        src/Application.cpp
)

add_executable(Voxelity ${SOURCE_FILES})
target_link_libraries(Voxelity ${CONAN_LIBS})