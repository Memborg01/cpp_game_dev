#pragma once
#include "course.hpp"
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Student : public User {
private:
  std::unordered_map<std::string, char> _grades;
  std::unordered_map<size_t, std::string> _courses;

public:
  Student(size_t ID, std::string &NAME,
          std::unordered_map<std::string, char> &GRADES,
          std::unordered_map<size_t, std::string> &COURSES);

  void AddGrade(std::string &course_name, char &grade);
  void AddCourse(Course *course);
  void GetCourses() const;
};
