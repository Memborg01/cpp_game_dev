
#include "course.hpp"
#include "education_base.hpp"

Course::Course(size_t ID, std::string &NAME, std::unordered_map<std::string, User*> &STUDENTS, 
      std::unordered_map<std::string, User*> &TEACHERS) : EducationBase(ID, NAME, STUDENTS, TEACHERS) {}
