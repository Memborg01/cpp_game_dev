#pragma once

#include "education_base.hpp"
#include "teacher.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>
class School : public EducationBase {
private:
  std::unordered_map<size_t, Course *> _courses;

public:
  School(size_t ID, std::string &NAME,
         std::unordered_map<std::string, User *> &STUDENTS,
         std::unordered_map<std::string, User *> &TEACHERS,
         std::unordered_map<size_t, Course *> COURSES);

  void AddStudent(User *student) override;
  void GetAllStudents() const override;

  void AddTeacher(User *teacher) override;
  void GetAllTeachers() const override;

  void AddCourse(Course *course);
  void GetAllCourses() const;
};
