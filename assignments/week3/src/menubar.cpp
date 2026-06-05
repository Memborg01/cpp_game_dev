#include "menubar.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <windows.h>

MenuBar::MenuBar() {}

void MenuBar::AddUiElements(GLFWwindow* window) {

  if (ImGui::BeginMenuBar()) {
    if (ImGui::BeginMenu("File")) {

      if (ImGui::MenuItem("Open..", "Ctrl+O")) {
      }

      if (ImGui::MenuItem("Save", "Ctrl+S")) {
      }

      if (ImGui::MenuItem("Close", "Ctrl+W")) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
      }

      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }
}
