#include "game.hpp"
#include "config.h"
#include "player.hpp"

Game::Game() : player(characterSheet), score(0), keys(0), state(PLAYING) {}
