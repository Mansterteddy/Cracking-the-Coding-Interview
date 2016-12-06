#ifndef __COMPANY__H__
#define __COMPANY__H__

#include "Person.h"
#include <iostream>

class Company
{
    public:
        Company(int size):
            num_employees(size), employees(new Person[size]){}
        
        Company():
            num_employees(DEFAULT_SIZE), employees(new Person[DEFAULT_SIZE]) {}

        void set_employee(int index, Person emp);

        Person get_employee(int index);

        friend std::ostream& operator<<(std::ostream& os, const Company& company);

    private:
        int num_employees;
        Person* employees;
        static const int DEFAULT_SIZE = 100;
};

#endif 