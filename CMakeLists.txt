cmake_minimum_required(VERSION 3.28)

project(Drift)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(Drift ${SOURCES})

target_include_directories(Drift PRIVATE include)

target_link_libraries(Drift PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)