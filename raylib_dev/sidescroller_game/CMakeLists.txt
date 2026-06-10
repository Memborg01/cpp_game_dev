cmake_minimum_required(VERSION 3.11)
project(SideScroller)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(raylib REQUIRED)

set(RAYLIB_DIR "C:/raylib/raylib/")
set(RAYLIB_LIB_DIR "C:/raylib/raylib/build/raylib/Release")

include_directories(${RAYLIB_DIR}/src)
link_directories(${RAYLIB_LIB_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)
