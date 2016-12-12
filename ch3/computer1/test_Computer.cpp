#include "Computer.h"
#include "Lap_Top.h"
#include <iostream>
using std::cout;
using std::endl;

/** Tests classes Computer and Lap_Top. Creates an object of each and
    displays them.
*/
int main() {
  Computer my_computer("Acme", "Intel P4 2.4", 512, 60);
  Lap_Top your_computer("DellGate", "AMD Athlon 2000", 256, 40, 
                        15.0, 7.5);
  cout << "My computer is :\n" << my_computer.to_string() << endl;
  cout << "\nYour computer is :\n" << your_computer.to_string()        << endl;
}
