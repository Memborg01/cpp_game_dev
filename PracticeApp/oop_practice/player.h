#pragma once
#include <iostream>

class Player {
public:
  Player(int u_value, std::string u_name) {
    value = u_value;
    name = u_name;
  }

  float test;
  void AddPoints(int points) { value += points; }
  void GetValue() { std::cout << value << "\n"; }

private:
  int value;
  std::string name;
};
