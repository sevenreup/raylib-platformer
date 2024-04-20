cmake_minimum_required(VERSION 3.10)

set(NAME "Platformer")

project(${NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

include(cmake/sourcelist.cmake)

source_group(
    ${sources}
)

file (GLOB SRC_FILES  src/*.cpp)
file (GLOB SRC_FILES  src/*.h)

add_executable(${NAME} src/main.cpp ${sources})

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game
)

target_link_libraries(${NAME} PRIVATE raylib)
target_link_libraries(${NAME} PRIVATE fmt::fmt-header-only)