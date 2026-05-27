
#include "school.hpp"
#include "course.hpp"
#include "education_base.hpp"
#include "user.hpp"
#include <iostream>

School::School(size_t ID, std::string &NAME,
               std::unordered_map<std::string, User *> &STUDENTS,
               std::unordered_map<std::string, User *> &TEACHERS,
               std::unordered_map<size_t, Course *> COURSES)
    : EducationBase(ID, NAME, STUDENTS, TEACHERS),
      _courses(std::move(COURSES)) {}

void School::AddCourse(Course *course) { _courses[course->GetId()] = course; }

void School::AddTeacher(User *teacher) {
  _teachers[teacher->GetName()] = teacher;
}

void School::AddStudent(User *student) {
  _students[student->GetName()] = student;
}

void School::GetAllCourses() const { std::cout << "All Courses" << "\n"; }

void School::GetAllStudents() const {
  std::cout << "Students in School:" << "\n";
  for (auto student : _students) {
    std::cout << student.second->GetName() << "\n";
  }
}

void School::GetAllTeachers() const { std::cout << "All Teachers" << "\n"; }
