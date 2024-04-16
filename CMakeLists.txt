cmake_minimum_required(VERSION 3.10)

project(raylib-intro)

find_package(raylib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(RaylibIntro main.cpp)

target_link_libraries(RaylibIntro PRIVATE raylib::raylib)
target_link_libraries(RaylibIntro PRIVATE fmt::fmt)