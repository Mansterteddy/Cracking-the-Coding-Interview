#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Address.h"
#include <string>
#include <algorithm>

class Employee
{
    public:
        Employee() {}

        Employee(const std::string& the_name, Address* the_address, double the_rate) : name(the_name), p_address(the_address),
        rate(the_rate), hours(0.0) {}

        //The copy construction
        Employee(const Employee& other);

        //The assignment operator
        Employee& operator=(const Employee& other);

        std::string get_name() const {return name;}

        //The destructer
        virtual ~Employee() {delete p_address;}

        void set_house_number(std::string new_house_number)
        {
            p_address->set_house_number(new_house_number);
        }

        std::string to_string() const;

        void swap(Employee& other)
        {
            std::swap(name, other.name);
            std::swap(p_address, other.p_address);
            std::swap(rate, other.rate);
            std::swap(hours, other.hours);
        }

    protected:
        std::string name;
        Address* p_address;
        double rate;
        double hours;
};

inline void swap(Employee& e1, Employee& e2)
{
    e1.swap(e2);
}

#endif