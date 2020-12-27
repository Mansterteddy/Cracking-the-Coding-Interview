#include "Student.h"
#include <sstream>

std::string Student::to_string() const
{
    std::ostringstream result;
    result<<name<<'\n'<<p_address->to_string()<<"Major: "<<major<<" GPA: "<<gpa;
    return result.str();
}

Student::Student(const Student& other) : name(other.name), p_address(other.p_address->clone()), major(other.major), gpa(other.gpa) {}

Student& Student::operator=(const Student& other)
{
    Student temp(other);
    swap(temp);
    return *this;
}