#pragma once

#include "animation.hpp"
#include "raylib.h"

struct Collectible {
  Vector2 position;
  float radius;
  bool collected;
  Animation animation;

  Collectible(Vector2 pos);
  void Update(float deltaTime);
  void Draw(Texture2D &spriteSheet);
  bool CheckCollision(const Rectangle &player);
};
