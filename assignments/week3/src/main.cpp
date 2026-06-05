#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include "mainCanvas.h"
#include "menubar.h"
#include "sidebar.h"
#include <filesystem>
#include <iostream>

#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <string>

namespace fs = std::filesystem;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

inline void MySaveFunction() { std::cout << "Saving.....\n"; }

int main() {

  if (!glfwInit()) {
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                        "UI_Module", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // imgui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();

  // renderer setup

  char dirInput[256] = "";
  std::string currentDir = ".";

  MainCanvas mc;
  MenuBar mb;
  Sidebar sb;

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // imgui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    // UI Code
    ImGui::Begin("App", nullptr, ImGuiWindowFlags_MenuBar);

    mb.AddUiElements(window);

    //ImGui::BeginChild("Sidebar");
    sb.AddUiElements(currentDir, dirInput, sizeof(dirInput));
    //ImGui::EndChild();

    mc.DrawMainCanvas(currentDir);

    ImGui::End();

    // Renderer
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
