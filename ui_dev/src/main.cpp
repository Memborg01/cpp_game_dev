#include <iostream>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

#include <GLFW/glfw3.h>
#include <gl/gl.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void MySaveFunction() { 
  std::cout << "Saving.....\n"; 
}

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
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // imgui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    char buf[256] = "";
    float f{0.5f};

    // UI Code
    ImGui::Begin("Hello, UI_APP");

    ImGui::Text("Hello, world %d", 12);
    if (ImGui::Button("Save")) {
      MySaveFunction();
    }
    ImGui::InputText("string", buf, IM_COUNTOF(buf));
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

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
