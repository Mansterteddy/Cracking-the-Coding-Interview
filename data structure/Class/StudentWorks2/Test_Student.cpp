#include "Student.h"

#include <iostream>
#include <ostream>

using std::cout;

int main() {

  //  Address* add1 = new US_Address("123", "Main St", "AnyCity",
  //                               "ZZ", "99999-9999");

  Address* add2 = new German_Address("345", "Musterstr", 
                                     "Musterstadt", "99999");

//Student s1("John Smith", add1, "CIS");

  Student s2("Johan Schmidt", add2, "IS&T");

//  cout << "Student 1: " << s1.to_string() << "\n\n";
  cout << "Student 2: " << s2.to_string() << "\n\n";

  return 0;
}
