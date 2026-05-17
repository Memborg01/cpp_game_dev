#include "book.hpp"
#include "item.hpp"
#include <cstddef>
#include <iostream>

Book::Book(size_t ID, float WEIGHT, float HEIGHT, std::string &NAME,
           std::string &TYPE, std::string &PUBLISHER, std::string &AUTHOR)
    : Item(ID, WEIGHT, HEIGHT, NAME, TYPE), m_publisher(PUBLISHER),
      m_author(AUTHOR) {}

void Book::GetItemInfo() const {
  std::cout << "The Book name: " << m_name << "\n";
  std::cout << "The Book author: " << m_author << "\n";
}
