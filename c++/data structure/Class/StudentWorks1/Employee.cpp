#include "Employee.h"

#include <sstream>
#include <ostream>

using std::string;
using std::ostringstream;

string Employee::to_string() const
{
    ostringstream result;
    result << name << '\n' <<p_address->to_string() << "Rate: " << rate << "Hours: " << hours;

    return result.str();
}

Employee::Employee(const Employee& other) : name(other.name), p_address(other.p_address->clone()), rate(other.rate), hours(other.hours) {}

Employee& Employee::operator=(const Employee& other)
{
    Employee temp(other);
    swap(temp);
    return *this;
}