#include "Company.h"
#include <iostream>

using std::cout;

int main()
{
    Company comp(2);
    comp.set_employee(0, Person("Elliot", "K", "123", 1942));
    comp.set_employee(1, Person("Paul", "W", "234", 1945));
    cout<<comp;
    return 0;
}