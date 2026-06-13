#pragma once

#include "player.hpp"
#include "raylib.h"
struct Enemy {
  Vector2 position;
  Vector2 startPos;
  float patrolDistance;
  float speed;
  float width, height;
  bool alive;
  int health;

  Enemy(float x, float y, float patrolDistance);

  void Update(float deltaTime, Player &player);

  void Draw(Texture2D &spriteSheet);

  Rectangle GetBounds() const;
};
