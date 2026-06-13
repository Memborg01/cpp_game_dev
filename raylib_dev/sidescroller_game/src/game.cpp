#include "game.hpp"
#include "config.h"
#include "player.hpp"
#include "raylib.h"

Game::Game() : player(characterSheet), score(0), keys(0), state(PLAYING) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game Demo");
  SetTargetFPS(60);

  characterSheet = LoadTexture("assets/character.png");
  environmentSheet = LoadTexture("assets/environment.png");

  camera.target = {0, 0};
  camera.offset = {SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f};
  camera.rotation = 0.0f;
  camera.zoom = 2.0f;

  CreateLevel();
}

void Game::CreateLevel() {
  // Ground platforms
  platforms.push_back({0, 600, 800, 120});
  platforms.push_back({900, 550, 400, 120});
  platforms.push_back({1400, 500, 300, 20});
  platforms.push_back({1800, 450, 200, 20});
  platforms.push_back({2100, 400, 200, 120});

  // Floating platforms
  platforms.push_back({300, 450, 100, 20});
  platforms.push_back({500, 350, 100, 20});
  platforms.push_back({700, 250, 100, 20});
}

void Game::Update(float deltaTime) {
  if (state != PLAYING) {
    return;
  }

  player.Update(deltaTime, platforms);
  camera.target = {player.position.x, player.position.y - 100};
}

void Game::Draw() {
  BeginDrawing();

  ClearBackground(SKYBLUE);
  BeginMode2D(camera);

  player.Draw(characterSheet);

  EndMode2D();
  EndDrawing();
}

void Game::HandleInput() {
  if (state == PAUSED && IsKeyPressed(KEY_P)) {
    state = PLAYING;
  } else if (state == PLAYING && IsKeyPressed(KEY_P)) {
    state = PAUSED;
  }
}

Game::~Game() {
  UnloadTexture(characterSheet);
  UnloadTexture(environmentSheet);
  CloseWindow();
}

bool Game::ShouldClose() const { return WindowShouldClose(); }
