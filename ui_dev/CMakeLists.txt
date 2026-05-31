cmake_minimum_required(VERSION 3.11)
project(ui_module)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(third_party/imgui)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
  imgui
  imgui_stdlib
  imgui_glfw
  imgui_opengl3
  glfw
  OpenGL::GL
)

