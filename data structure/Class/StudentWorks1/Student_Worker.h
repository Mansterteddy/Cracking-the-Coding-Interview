#ifndef STUDENT_WORKER_H_
#define STUDENT_WORKER_H_

#include "Employee.h"
#include "Student.h"

class Student_Worker : public Employee, public Student
{
    public:

        Student_Worker(const std::string& the_name, Address* the_address, double the_rate, const std::string& the_major):
        Employee(the_name, the_address, the_rate), Student(the_name, the_address, the_major) {}

        std::string to_string() const;
};

#endif