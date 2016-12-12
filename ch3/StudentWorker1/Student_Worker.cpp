#include "Student_Worker.h"
#include <sstream>

/** Return string representation of student worker. */
std::string Student_Worker::to_string() const {
  std::ostringstream result;
  result << name << '\n' 
         << p_address->to_string()
         << "\nMajor: " << major 
         << " GPA: " << gpa
         << " rate: " << rate
         << " hours: " << hours;
  return result.str();
}
