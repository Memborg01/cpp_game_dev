
#include "student.hpp"
#include "course.hpp"
#include "user.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
Student::Student(size_t ID, std::string &NAME,
                 std::unordered_map<std::string, char> &GRADES,
                 std::unordered_map<size_t, std::string> &COURSES)
    : User(ID, NAME), _grades(std::move(GRADES)), _courses(std::move(COURSES)) {
}

void Student::AddGrade(std::string &courseName, char &grade) {
  _grades[courseName] = grade;
}

void Student::AddCourse(Course *course) {
  _courses[course->GetId()] = course->GetName();
}

void Student::GetCourses() const {
  std::cout << "Courses for student " << GetName() << ":\n";
  for (auto course : _courses) {
    std::cout << course.second << "\n";
  }
}
