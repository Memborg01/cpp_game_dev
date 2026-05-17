#include "store.hpp"
#include <algorithm>
#include <string>
#include <utility>
Store::Store(size_t ID, std::string &NAME,
             std::unordered_map<std::string, Item *> &ITEMS)
    : m_id(std::move(ID)), m_name(NAME), m_items(std::move(ITEMS)) {};
