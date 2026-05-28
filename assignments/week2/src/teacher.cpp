#include "teacher.hpp"
#include "course.hpp"
#include "user.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

Teacher::Teacher(size_t ID, std::string &NAME,
                 std::unordered_map<size_t, Course *> &COURSES)
    : User(ID, NAME), _courses(std::move(COURSES)) {}

void Teacher::AddCourse(Course *course) {
  size_t id = course->GetId();
  _courses[id] = course;
}

void Teacher::GetCourses() const {
  for (auto course : _courses) {
    std::cout << "Course Id: " << course.first
              << ", Name: " << course.second->GetName() << "\n";
  }
}
