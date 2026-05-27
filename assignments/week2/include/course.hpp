#pragma once
#include "education_base.hpp"
#include "student.hpp"
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

class Course : public EducationBase {
private:
public:
  Course(size_t ID, std::string &NAME,
         std::unordered_map<std::string, User *> &STUDENT,
         std::unordered_map<std::string, User *> &TEACHERS);

  std::string GetName() const;
  size_t GetId() const;
  void GetInfo() const;

  void AddStudent(User *student) override;
  void AddTeacher(User *teacher) override;
};
