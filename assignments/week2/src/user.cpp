
#include "user.hpp"
#include <algorithm>
#include <string>
User::User(size_t ID, std::string &NAME) : _id(std::move(ID)), _name(NAME) {}

std::string User::GetName() const {
 return _name;
}
