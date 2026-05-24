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
    Course(std::unordered_map<std::string, User*> &STUDENT, std::unordered_map<std::string, User*> &TEACHER, size_t ID, std::string &NAME);
    void GetInfo() const;
    void AddStudent(Student &Student) const;
    void AddTeacher(Teacher &Teacher) const;
};
