#include "course.hpp"
#include "school.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

int main() {

  std::unordered_map<std::string, User *> students;
  std::unordered_map<std::string, User *> teachers;
  std::unordered_map<size_t, Course *> courses;
  std::string schoolName = "MyWay";

  School *school = new School(1, schoolName, students, teachers, courses);

  std::string studentName1 = "Jakob";
  std::unordered_map<std::string, char> studentGrades1;
  std::unordered_map<size_t, std::string> studentCourses1;
  Student *jakob =
      new Student(0, studentName1, studentGrades1, studentCourses1);

  std::string studentName2 = "Jonas";
  std::unordered_map<std::string, char> studentGrades2;
  std::unordered_map<size_t, std::string> studentCourses2;
  Student *jonas =
      new Student(0, studentName2, studentGrades2, studentCourses2);

  school->AddStudent(jakob);
  school->AddStudent(jonas);

  school->GetAllStudents();

  return 0;
}
