#include "course.hpp"
#include "school.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "user.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>

int main() {

  // Create School

  std::unordered_map<std::string, User *> students;
  std::unordered_map<std::string, User *> teachers;
  std::unordered_map<size_t, Course *> courses;
  std::string schoolName = "MyWay";

  School *school = new School(1, schoolName, students, teachers, courses);

  // Create Students

  std::string studentName1 = "Jakob";
  std::unordered_map<std::string, char> studentGrades1;
  Student *jakob = new Student(0, studentName1, studentGrades1);

  std::string studentName2 = "Jonas";
  std::unordered_map<std::string, char> studentGrades2;
  Student *jonas = new Student(0, studentName2, studentGrades2);

  school->AddStudent(jakob);
  school->AddStudent(jonas);

  // Create teachers

  std::string teacherName = "Felipe";
  Teacher *felipe = new Teacher(10, teacherName, courses);
  school->AddTeacher(felipe);

  std::string teacherName2 = "John";
  Teacher *john = new Teacher(10, teacherName2, courses);
  school->AddTeacher(felipe);
  school->AddTeacher(john);

  // Create courses

  std::string mathCourseName = "Mathmatics";
  Course *math = new Course(0, mathCourseName, students, teachers);
  math->AddStudent(jakob);
  math->AddTeacher(john);

  std::string cppCourseName = "Programming with C++";
  Course *cpp = new Course(1, cppCourseName, students, teachers);
  cpp->AddStudent(jakob);
  cpp->AddStudent(jonas);
  cpp->AddTeacher(felipe);

  school->AddCourse(math);
  school->AddCourse(cpp);

  school->GetAllStudents();
  school->GetAllTeachers();
  school->GetAllCourses();

  return 0;
}
