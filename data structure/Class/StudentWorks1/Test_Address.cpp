#include "Address.h"

#include <iostream>

using std::cout;

int main()
{
    Address* add2 = new German_Address("345", "Bahnhofstr", "Jedenstadt", "D-99999");

    cout<<add2->to_string()<<"\n\n";

    return 0;
}
