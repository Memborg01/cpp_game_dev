#include "enemy.hpp"
#include "config.h"
#include "player.hpp"
#include "raylib.h"
#include <math.h>

Enemy::Enemy(float x, float y, float patrolDist = 100)
    : position({x, y}), startPos({x, y}), patrolDistance(patrolDist), speed(50),
      width(32), height(48), alive(true), health(2) {}

void Enemy::Update(float deltaTime, Player &player) {
  if (!alive) {
    return;
  }

  float offset = sin(GetTime() * speed * 0.01) * patrolDistance;
  position.x = startPos.x + offset;

  if (player.state == ATTACKING &&
      CheckCollisionRecs(GetBounds(), player.GetAttackHitBox())) {
    health--;
    if (health <= 0) {
      alive = false;
    }
  }

  if (CheckCollisionRecs(GetBounds(), player.GetBounds())) {
    if (player.position.x < position.x) {
      player.position.x -= 20;
    } else {
      player.position.x += 20;
    }
    player.ApplyDamage(1.f);
  }
}

void Enemy::Draw(Texture2D &spriteSheet) {
  if (!alive) {
    return;
  }

  Rectangle source = {0, PLAYER_SIZE * 3, PLAYER_SIZE,
                      PLAYER_SIZE};

  Rectangle dest = {position.x, position.y, width, height};
  DrawTexturePro(spriteSheet, source, dest, {0, 0}, 0, WHITE);
}

Rectangle Enemy::GetBounds() const {
  return {position.x, position.y, width, height};
}
