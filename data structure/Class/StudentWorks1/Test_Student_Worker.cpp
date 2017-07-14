#include <iostream>
#include <ostream>
#include "Student_Worker.h"

using std::cout;

int main()
{
    Address* add2 = new German_Address("345", "Musterstr", "Musterstadt", "99999");

    Student_Worker sw2("Johan Schmidt", add2, 30.0, "IS&T");

    cout<<"StudentWorker 2: "<<sw2.to_string()<<"\n\n";
    cout<<"StudentWorker 2.gpa: "<<sw2.get_gpa()<<"\n\n";
    cout<<"StudentWorker 2.name: "<<sw2.get_name()<<"\n\n";

    cout<<"Any Wrong?";
    return 0;
}