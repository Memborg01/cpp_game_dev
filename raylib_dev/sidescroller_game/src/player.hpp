#pragma once

#include "animation.hpp"
#include "config.h"
#include "raylib.h"
#include <vector>

struct Player {
  Vector2 position;
  Vector2 velocity;
  Vector2 checkpoint;
  float width, height;
  float attackTimer;
  float health;
  bool facingRight;
  bool isGrounded;
  bool canAttack;
  bool hasDied;

  PlayerState state;
  Animation *currentAnim;
  Animation idleAnim;
  Animation runAnim;
  Animation jumpAnim;
  Animation attackAnim;

  Player(Texture2D &spriteSheet);

  void Update(float deltaTime, const std::vector<Rectangle> &platforms);
  void Draw(Texture2D &spriteSheet);
  void ApplyDamage(const float damage);
  Rectangle GetBounds() const;
  Rectangle GetAttackHitBox() const;
  float GetHealth() { return health; };
};
