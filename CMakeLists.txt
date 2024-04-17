cmake_minimum_required(VERSION 3.10)

project(RaylibIntro)

# set(CMAKE_TOOLCHAIN_FILE C:/bin/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(raylib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(RaylibIntro main.cpp)

# target_include_directories(RaylibIntro PUBLIC raylib "include" )

target_link_libraries(RaylibIntro PRIVATE raylib)
# target_link_libraries(RaylibIntro PRIVATE raylib_static)
target_link_libraries(RaylibIntro PRIVATE fmt::fmt-header-only)