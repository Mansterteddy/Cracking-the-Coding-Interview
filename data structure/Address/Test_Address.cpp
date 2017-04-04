#include "Address.h"
#include <iostream>

using std::cout;

int main()
{
    Address* add1 = new German_Address("345", "Bahnhofstr", "Jedenstadt", "D-99999");

    cout << add1->to_string() << "\n";

    return 0;
}