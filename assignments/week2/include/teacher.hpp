#pragma once
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Course;

class Teacher : public User {
private:
  std::unordered_map<size_t, Course *> _courses;

public:
  Teacher(size_t ID, std::string &NAME,
          std::unordered_map<size_t, Course *> &COURSES);

  void GetCourses() const;

  void AddCourse(Course *course);
};
