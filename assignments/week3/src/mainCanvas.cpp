#include "mainCanvas.h"
#include "sidebar.h"
#include <filesystem>
#include <imgui.h>
#include <string>

namespace fs = std::filesystem;

MainCanvas::MainCanvas(){

}

void MainCanvas::DrawMainCanvas(std::string &currentDir) {


  ImGui::BeginChild("Main Canvas");

  ImGui::Text("Current directory:");
  ImGui::Text("%s", currentDir.c_str());
  ImVec2 btnSize = ImVec2(50, 20);

  if (ImGui::Button("Up", btnSize)) {
    fs::path path(currentDir);
    if (path.has_parent_path()) {
    currentDir = path.parent_path().string();
    }
  }

  ImGui::Separator();

  try {
    for (const auto &entry : fs::directory_iterator(currentDir)) {
      std::string filename = entry.path().filename().string();

      if (entry.is_directory()) {
        std::string label = "[DIR] " + filename;

        if (ImGui::Selectable(label.c_str())) {
          currentDir = entry.path().string();
        }
      } else {
        ImGui::Text("     %s", filename.c_str());
      }
    }
  } catch (const fs::filesystem_error &e) {
    ImGui::TextColored(ImVec4(1.0f, 0.2f, 0.2f, 1.0f),
                       "Could not open directory.");
  }
  ImGui::EndChild();
}
