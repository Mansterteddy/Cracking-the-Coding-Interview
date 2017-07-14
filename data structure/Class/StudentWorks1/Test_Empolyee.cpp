#include "Employee.h"

#include <iostream>
#include <ostream>

using std::cout;

int main()
{
    Address* add2 = new German_Address("345", "Musterstr", "Musterstadt", "99999");

    Employee e2("Johan Schmidt", add2, 30.);

    cout<<"Employee 2: "<<e2.to_string()<<"\n";

    return 0;
}