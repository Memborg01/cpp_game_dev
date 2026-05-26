
#include "school.hpp"
#include "education_base.hpp"

School::School(size_t ID, std::string &NAME, std::unordered_map<std::string, User*> &STUDENTS, 
      std::unordered_map<std::string, User*> &TEACHERS, std::unordered_map<size_t, EducationBase*> COURSES) :
  EducationBase(ID, NAME, STUDENTS, TEACHERS), _courses(std::move(COURSES)) {}
