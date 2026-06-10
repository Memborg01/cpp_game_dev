#include "player.hpp"
#include "raylib.h"

const int PLAYER_SIZE_WIDTH = 32;
const int PLAYER_SIZE_HEIGHT = 48;

Player::Player(Texture2D &spriteSheet)
    : position({100, 300}), velocity({0, 0}), width(PLAYER_SIZE_WIDTH),
      height(PLAYER_SIZE_HEIGHT), facingRight(true), isGrounded(false),
      canAttack(true), attackTimer(0), state(IDLE),
      idleAnim({{0, 0, PLAYER_SIZE_WIDTH, PLAYER_SIZE_HEIGHT}, 4}),
      runAnim({0, PLAYER_SIZE_HEIGHT, PLAYER_SIZE_WIDTH, PLAYER_SIZE_HEIGHT},
              6),
      jumpAnim(
          {0, PLAYER_SIZE_HEIGHT * 2, PLAYER_SIZE_WIDTH, PLAYER_SIZE_HEIGHT},
          6),
      attackAnim(
          {0, PLAYER_SIZE_HEIGHT * 3, PLAYER_SIZE_WIDTH, PLAYER_SIZE_HEIGHT},
          6) {
  currentAnim = &idleAnim;
}
