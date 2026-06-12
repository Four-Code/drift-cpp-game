cmake_minimum_required(VERSION 3.16)

project(Drift)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Drift ${SOURCES})

target_include_directories(Drift PRIVATE include)

target_link_libraries(Drift PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)