#include "clock.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Clock c;
    c.set_clock(12, 59, 58);
    c.tick();
    c.tick();
    c.tick();
    c.tick();
    cout<<setfill('0');
    cout<<"The new time is: "
    <<setw(2)<<c.get_hours()<<":"
    <<setw(2)<<c.get_minutes()<<":"
    <<setw(2)<<c.get_seconds()<<"\n";

    return 0;
}
