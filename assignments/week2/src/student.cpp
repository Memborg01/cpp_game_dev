
#include "student.hpp"
#include "user.hpp"
#include <string>
#include <utility>

Student::Student(size_t ID, std::string &NAME,
                 std::unordered_map<std::string, char> &GRADES)
    : User(ID, NAME), _grades(std::move(GRADES)) {
}

void Student::AddGrade(std::string &courseName, char &grade) {
  _grades[courseName] = grade;
}

