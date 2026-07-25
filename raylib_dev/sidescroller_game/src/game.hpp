#pragma once

#include "collectible.hpp"
#include "config.h"
#include "door.hpp"
#include "enemy.hpp"
#include "parralax.h"
#include "player.hpp"
#include "raylib.h"
#include <vector>

struct Game {
  int id;
  GameState state;

  Texture2D characterSheet;
  Texture2D environmentSheet;

  Player player;
  std::vector<Rectangle> platforms;
  std::vector<Collectible> coins;
  std::vector<Door> doors;
  std::vector<Enemy> enemies;

  Camera2D camera;

  int score;
  int keys;

  std::vector<ParallaxLayer> bgLayers;

  Game();
  ~Game();

  void CreateLevel();
  void Update(float deltaTime);
  void Draw();
  void HandleInput();
  bool ShouldClose() const;
};
