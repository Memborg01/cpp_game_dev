#include "collectible.hpp"
#include "animation.hpp"
#include "raylib.h"

Collectible::Collectible(Vector2 pos)
    : position(pos), radius(16.0f), collected(false),
      animation({0, 200, 16, 16}, 8) {};

void Collectible::Update(float deltaTime) {
  if (!collected) {
    animation.Update(deltaTime);
  }
}

void Collectible::Draw(Texture2D &spriteSheet) {
  if (collected) {
    return;
  }

  Rectangle source = animation.GetCurrentFrame();
  Rectangle dest = {position.x - radius, position.y - radius, radius * 2.f,
                    radius * 2.f};
  DrawTexturePro(spriteSheet, source, dest, {0, 0}, 0, WHITE);
};

bool Collectible::CheckCollision(const Rectangle &player) {
  if (collected) {
    return false;
  }

  Rectangle itemRect = {position.x - radius, position.y - radius, radius * 2.f,
                        radius * 2.f};

  return CheckCollisionRecs(player, itemRect);
};
