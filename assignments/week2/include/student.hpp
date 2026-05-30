#pragma once
#include "course.hpp"
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Student : public User {
private:
  std::unordered_map<std::string, char> _grades;

public:
  Student(size_t ID, std::string &NAME,
          std::unordered_map<std::string, char> &GRADES);

  void AddGrade(std::string &course_name, char &grade);
};
