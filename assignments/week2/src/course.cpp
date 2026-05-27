
#include "course.hpp"
#include "education_base.hpp"
#include "student.hpp"
#include "user.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Course::Course(size_t ID, std::string &NAME,
               std::unordered_map<std::string, User *> &STUDENTS,
               std::unordered_map<std::string, User *> &TEACHERS)
    : EducationBase(ID, NAME, STUDENTS, TEACHERS) {}

std::string Course::GetName() const { return _name; }
size_t Course::GetId() const { return _id; }

void Course::AddStudent(User *student) {
  std::string name = student->GetName();
  _students[name] = student;
}

void Course::AddTeacher(User *teacher) {
  std::string name = teacher->GetName();

  _teachers[name] = teacher;
}

void Course::GetInfo() const {
  std::cout << "Teachers:" << "\n";
  for (auto teacher : _teachers) {
    std::cout << teacher.second->GetName() << "\n";
  }
  std::cout << "\n";
  std::cout << "Students:" << "\n";
  for (auto student : _students) {
    std::cout << student.second->GetName() << "\n";
  }
}
