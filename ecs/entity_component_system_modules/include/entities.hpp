#pragma once

#include "entity.hpp"

struct Person : public Entity {
  float _weight;
  std::string _name;
};

struct Animal : public Entity {
  float _weight;
  std::string _species;
};
