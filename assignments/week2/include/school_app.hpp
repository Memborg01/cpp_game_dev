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
#include "student.hpp"
#include "teacher.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>
class School {
private:
  size_t _id;
  std::string _name;
  std::unordered_map<size_t, Course> _courses;
  std::unordered_map<size_t, Student> _students;

public:

  void AddStudent(User &student) const;
  void GetAllStudents() const;

  void AddTeacher(User &teacher) const;
  void GetAllTeachers() const;

  void AddCourse(Course &course) const;
  void GetAllCourses() const;

};
