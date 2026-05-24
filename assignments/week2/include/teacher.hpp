#pragma once
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Course;

class Teacher : User {
private:
  std::unordered_map<size_t, Course> _courses;

public:
  Teacher(size_t ID, std::string &NAME, Course &COURSES);

  void GetCourses() const;
  void GetCourseStudents(size_t ID) const;

};
