#include "Employee.h"
#include <iostream>
#include <ostream>

using std::cout;

int main() 
{

  //  Address* add1 = new US_Address("123", "Main St", "AnyCity",
  //                               "ZZ", "99999-9999");

  Address* add2 = new German_Address("345", "Musterstr", 
                                     "Musterstadt", "99999");

//  Employee e1("John Smith", add1, 25.);

  Employee e2("Johan Schmidt", add2, 30.);

//  cout << "Employee 1: " << e1.to_string() << '\n';
  cout << "Employee 2: " << e2.to_string() << '\n';

  return 0;
}
