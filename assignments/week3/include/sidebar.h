#pragma once
#include <cstddef>
#include <string>

class Sidebar {
private:
  char buf[256];
  float f;

public:
  Sidebar();
  void AddUiElements(std::string &currentDir, char *dirInput, size_t inputSize);
};
