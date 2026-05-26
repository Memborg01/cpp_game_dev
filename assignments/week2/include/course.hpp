#pragma once
#include "education_base.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Teacher;
class Student;

class Course : EducationBase {
  private:

  public:
    Course(size_t ID, std::string &NAME, std::unordered_map<std::string, User*> &STUDENT, std::unordered_map<std::string, User*> &TEACHERS);
    void GetInfo() const;
    void AddStudent(User &student) const;
    void AddTeacher(User &teacher) const;
};
