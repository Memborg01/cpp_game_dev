#pragma once
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Student : User {
private:

  std::unordered_map<std::string, char> grades;
  std::unordered_map<size_t, std::string> courses;

public:
  Student(size_t ID, std::string &NAME, std::unordered_map<std::string, char> &GRADES, std::unordered_map<size_t, std::string> &COURSES);

  void GetName() const override;
  void AddGrade(std::string &course_name, char &grade) const;
  void GetCourses() const;
};
