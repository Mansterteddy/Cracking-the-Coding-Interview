#include "Student.h"

#include <iostream>
#include <ostream>

using std::cout;

int main()
{
    Address* add2 = new German_Address("345", "Musterstr", "Musterstadt", "99999");

    Student s2("Johan Schmidt", add2, "IS&T");

    cout<<"Student 2: "<<s2.to_string()<<"\n\n";

    return 0;
}