#include "item.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

Item::Item(size_t ID, float WEIGHT, float HEIGHT, std::string &NAME,
           std::string &TYPE)
    : m_id(std::move(ID)), m_weight(WEIGHT), m_height(HEIGHT), m_name(NAME),
      m_type(TYPE) {}
