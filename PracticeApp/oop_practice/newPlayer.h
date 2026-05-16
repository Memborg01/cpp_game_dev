#pragma once
#include "player.h"

class NewPlayer : public Player {
private:
  float testVal;

public:
  NewPlayer(int u_value, std::string u_name, float u_testVal)
      : Player(u_value, u_name) {
    testVal = u_testVal;
  }

  void GetTest() { std::cout << testVal << "\n"; }
};
