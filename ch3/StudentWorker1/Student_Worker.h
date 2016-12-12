#ifndef STUDENT_WORKER_H_
#define STUDENT_WORKER_H_

#include "Employee.h"
#include "Student.h"

class Student_Worker : public Employee, public Student {
  public:
    /** Construct a new Student_Worker.
        @param the_name The Student_Worker's name
        @param the_address Pointer to the address
        @param the_rate The hourly rate
        @param the_major The student's major
    */
    Student_Worker(const std::string& the_name,
                   Address* the_address,
                   double the_rate,
                   const std::string& the_major) :
      Employee(the_name, the_address, the_rate),
      Student(the_name, the_address, the_major) {}

    /** Return a string representation of a student worker. */
    std::string to_string() const;
};

#endif
