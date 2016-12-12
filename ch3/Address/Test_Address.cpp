#include "Address.h"
#include <iostream>

using std::cout;

int main()
{
    Address* add1 = new US_Address("123", "Main St", "Somecity",
                                 "ZZ", "99999-9999" );
    Address* add2 = new German_Address("345", "Bahnhofstr", 
                                     "Jedenstadt", "D-99999");
    cout<<add1->to_string()<<"\n";
    cout<<add2->to_string()<<"\n";
    return 0;
}