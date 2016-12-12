/** Program to demonstrate the polymorphic nature of the
    Computer and Lap_Top classes
*/

#include "Computer.h"
#include "Lap_Top.h"
#include <iostream>
using namespace std;

int main()
{

  Computer* comp[3];
  comp[0] = new Computer("Ace", "AMD Anthlon 2500", 512, 60);
  comp[1] = new Lap_Top("Intel P4 2.4", 256, 40, 15.5, 7.5);
  comp[2] = comp[1];
  for (int i = 0; i < 3; i++) {
    cout << comp[i]->get_ram_size() << endl
	 << comp[i]->to_string() << endl;
  }
}
