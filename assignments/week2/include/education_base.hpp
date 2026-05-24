#pragma once
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class EducationBase {
  protected:
    size_t _id;
    std::string _name;

    std::unordered_map<std::string, User*> _students;
    std::unordered_map<std::string, User*> _teachers;

  public:
    EducationBase(size_t ID, std::string &NAME, std::unordered_map<std::string, User*> &STUDENTS, std::unordered_map<std::string, User*> &TEACHER);

  virtual void AddStudent(User &student) = 0;
  virtual void GetAllStudents() const = 0;

  virtual void AddTeacher(User &teacher) = 0;
  virtual void GetAllTeachers() const = 0;
};
