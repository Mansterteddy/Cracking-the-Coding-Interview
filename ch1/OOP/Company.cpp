#include "Company.h"
#include <ostream>

using std::ostream;
using std::endl;

void Company::set_employee(int index, Person emp)
{
    if(index >= 0 && index < num_employees)
        employees[index] = emp;
}

Person Company::get_employee(int index)
{
    if(index >= 0 && index < num_employees)
        return employees[index];
    else
        return Person();
}

ostream& operator<<(ostream& os, const Company& company)
{
    for(int i = 0; i < company.num_employees; ++i)
    {
        os<<company.employees[i]<<endl;
    }
    return os;
}