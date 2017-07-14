#include "Computer.h"
#include "Lap_Top.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    /*Computer my_computer("Acme", "Intel P4 2.4", 512, 60);
    Lap_Top your_computer("DellGate", "AMD Athlon 2000", 256, 40, 15.0, 7.5);

    cout<<"My computer is: \n"<<my_computer.to_string()<<endl;
    cout<<"\nYour computer is: \n"<<your_computer.to_string()<<endl;
    */

    Computer* my_computer = new Computer("Acme", "Intel P4 2.4", 512, 60);
    cout<<"My computer is: \n"<<my_computer->to_string()<<endl;
    delete my_computer;

    my_computer = new Lap_Top("DellGate", "AMD Athlon 2000", 256, 40, 15.0, 7.5);
    cout<<"\nYour computer is: \n"<<my_computer->to_string()<<endl;
    delete my_computer;

    return 0;
}