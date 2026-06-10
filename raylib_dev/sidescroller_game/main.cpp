#include "game.hpp"
#include "raylib.h"

int main() {
  Game game;

  while (!game.ShouldClose()) {

    float deltaTime = GetFrameTime();

    game.HandleInput();

    game.Update(deltaTime);

    game.Draw();

  }

  return 0;
}
