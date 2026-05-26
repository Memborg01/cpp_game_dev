#pragma once
/*
 * Create a schoool app
 * The School app should be able to add classes/courses
 * - Method with pass in course ID, course name, max students, &Teacher
 *   Add &students to course
 *   Add &teacher to course
 *
 * Grade a student: Pass course Id, Grade and notes
 *   */

#include "course.hpp"
#include "education_base.hpp"
#include "teacher.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>
class School : EducationBase {
private:
  std::unordered_map<size_t, EducationBase*> _courses;

public:
  School(size_t ID, std::string &NAME, std::unordered_map<std::string, User*> &STUDENTS, 
      std::unordered_map<std::string, User*> &TEACHERS, std::unordered_map<size_t, EducationBase*> COURSES);

  void AddStudent(User &student) override;
  void GetAllStudents() const override;

  void AddTeacher(User &teacher) override;
  void GetAllTeachers() const override;

  void AddCourse(Course &course) const;
  void GetAllCourses() const;

};
