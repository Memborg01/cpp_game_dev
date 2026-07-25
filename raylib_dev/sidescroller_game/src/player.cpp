#include "player.hpp"
#include "config.h"
#include "raylib.h"

Player::Player(Texture2D &spriteSheet)
    : position({100, 350}), velocity({0, 0}), checkpoint({100, 350}), width(PLAYER_SIZE),
      height(PLAYER_SIZE), facingRight(true), isGrounded(false),
      canAttack(true), hasDied(false), attackTimer(0), health(3.0f), state(IDLE),
      idleAnim({{0, 0, PLAYER_SIZE, PLAYER_SIZE}, 4}),
      runAnim({0, PLAYER_SIZE, PLAYER_SIZE, PLAYER_SIZE}, 6),
      jumpAnim({0, PLAYER_SIZE * 2, PLAYER_SIZE, PLAYER_SIZE}, 8),
      attackAnim({0, PLAYER_SIZE * 3, PLAYER_SIZE, PLAYER_SIZE}, 3) {
  currentAnim = &idleAnim;
  health = 3.0f;
}

void Player::Update(float deltaTime, const std::vector<Rectangle> &platforms) {
  if (hasDied) {
    position = checkpoint;
    health = 3.0f;
    hasDied = false;
  }

  velocity.x = 0;

  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
    velocity.x = -PLAYER_SPEED;
    facingRight = false;

    if (isGrounded && state != ATTACKING) {
      state = RUNNING;
    }
  }

  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
    velocity.x = PLAYER_SPEED;
    facingRight = true;
    if (isGrounded && state != ATTACKING) {
      state = RUNNING;
    }
  }

  // jump mechanism
  if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W)) && isGrounded &&
      state != ATTACKING) {

    velocity.y = JUMP_FORCE;
    isGrounded = false;
    state = JUMPING;
  }

  // attack
  if (IsKeyDown(KEY_J) && canAttack) {
    state = ATTACKING;
    canAttack = false;
    attackTimer = 0.4f;
  }

  // gravity
  if (!isGrounded) {
    velocity.y += GRAVITY * deltaTime;
  }

  Vector2 prevPos = position;

  position.x += velocity.x * deltaTime;

  Rectangle playerRectX = {position.x, prevPos.y, width, height};
  for (const auto &plat : platforms) {
    if (CheckCollisionRecs(playerRectX, plat)) {
      if (velocity.x > 0) {
        position.x = plat.x - width;
      } else if (velocity.x < 0) {
        position.x = plat.x + plat.width;
      }
      velocity.x = 0;
    }
  }

  position.y += velocity.y * deltaTime;

  // Platform collision
  isGrounded = false;
  Rectangle playerRect = GetBounds();

  for (const auto &platform : platforms) {
    if (CheckCollisionRecs(playerRect, platform)) {
      // land on top
      if (velocity.y > 0 && prevPos.y + height <= platform.y + 5) {
        position.y = platform.y - height;
        velocity.y = 0;
        isGrounded = true;
      }

      // Hitting head
      else if (velocity.y < 0 &&
               prevPos.y >= platform.y + platform.height - 5) {
        position.y = platform.y + platform.height;
        velocity.y = 0;
      }
    }
  }

  // Screen boundaries
  if (position.x < 0) {
    position.x = 0;
  }
  if (position.x > 5000) {
    position.x = 5000;
  }

  // Attack timer
  if (!canAttack) {
    attackTimer -= deltaTime;
    if (attackTimer <= 0) {
      canAttack = true;
      if (isGrounded) {
        state = IDLE;
      } else {
        state = JUMPING;
      }
    }
  }

  if (state == RUNNING && velocity.x == 0.0f) {
    state = IDLE;
  }

  switch (state) {
  case IDLE:
    currentAnim = &idleAnim;
    break;
  case RUNNING:
    currentAnim = &runAnim;
    break;
  case JUMPING:
    currentAnim = &jumpAnim;
    break;
  case ATTACKING:
    currentAnim = &attackAnim;
    break;
  }

  currentAnim->Update(deltaTime);
}

void Player::Draw(Texture2D &spriteSheet) {
  Rectangle source = currentAnim->GetCurrentFrame();

  if (!facingRight) {
    source.width = -source.width;
  }

  Rectangle dest = {position.x, position.y, width, height};
  Vector2 origin = {0, 0};

  DrawTexturePro(spriteSheet, source, dest, origin, 0.0f, WHITE);
}

void Player::ApplyDamage(const float damage) {
  health -= damage;
  if (health <= 0) {
    hasDied = true;
  }
}

Rectangle Player::GetBounds() const {
  return {position.x, position.y, width, height};
}

Rectangle Player::GetAttackHitBox() const {
  if (state != ATTACKING) {
    return {0, 0, 0, 0};
  }

  float attackRange = 30.0f;
  if (facingRight) {
    return {position.x + width, position.y - height * 0.5f, attackRange, height};
  } else {
    return {position.x - width, position.y - height * 0.5f, attackRange, height};
  }
}
