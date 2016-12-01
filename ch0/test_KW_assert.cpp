#include <iostream>
#include "KW_assert.h"

using std::cout;

int main()
{
    int x = 5;
    kw_assert(x < 4);
    cout<<"Test of assertion macro failed\n";
    return 0;
}