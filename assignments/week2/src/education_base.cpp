#include "education_base.hpp"
#include <algorithm>
#include <cstddef>
#include <utility>

EducationBase::EducationBase(size_t ID, std::string &NAME, std::unordered_map<std::string, 
    User*> &STUDENTS, std::unordered_map<std::string, User*> &TEACHERS) : _id(std::move(ID)), _name(NAME), _students(std::move(STUDENTS)), 
  _teachers(std::move(TEACHERS)) {}
