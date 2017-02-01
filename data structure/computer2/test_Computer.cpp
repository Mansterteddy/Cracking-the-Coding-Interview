#include "Computer.h"
#include "Lap_Top.h"
#include <iostream>
using std::cout;
using std::endl;

/** Tests classes Computer and LapTop. Creates an object of each and
    displays them.
*/
int main() {
    Computer my_computer("Acme", "Intel P4 2.4", 512, 60);
    Lap_Top your_computer("DellGate", "AMD Athlon 2000", 256, 40, 
			15.0, 7.5);
    cout << "My computer is :\n" << my_computer.to_string() << '\n';
    cout << "\nYour computer is :\n" << your_computer.to_string() << '\n';
    cout << endl << endl;
Lap_Top ltp1("Intel P4 2.8", 256, 40, 14, 6.5);
Lap_Top ltp2("MicroSys", "AMD Athlon 2000", 256, 40, 15, 7.5);
    cout << "LapTop1 is :\n" << ltp1.to_string() << '\n';
    cout << "\nLapTop2 is :\n" << ltp2.to_string() << '\n';
Computer* the_computer;
the_computer = new Lap_Top("Bravo", "Intel P4 2.4", 256, 40, 15.0, 7.5);
cout << the_computer->to_string() << endl;
    delete the_computer;
the_computer = new Lap_Top("Bravo", "Intel P4 2.4", 256, 40, 15.0, 7.5);
cout << the_computer->to_string() << endl;
}
