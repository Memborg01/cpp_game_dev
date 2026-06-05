#include "sidebar.h"
#include "systemService.h"
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <imgui.h>

namespace fs = std::filesystem;

Sidebar::Sidebar() {
  strcpy(buf, "");
  f = 0.5f;
}

void Sidebar::AddUiElements(std::string &currentDir, char *dirInput,
                            size_t inputSize) {
  SystemService sysService;

  ImGui::Text("Hello, world %d", 12);
  if (ImGui::Button("Save")) {
    sysService.SaveSettings();
  }

  ImGui::InputText("Directory", dirInput, inputSize);
  if (ImGui::Button("Open Directory")) {
    if (fs::exists(dirInput) && fs::is_directory(dirInput)) {
      currentDir = dirInput;
    }
  }

  ImGui::InputText("string", buf, IM_COUNTOF(buf));
  ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
}
