#include "Computer.h"
#include <sstream>

using std::ostringstream;
using std::string;

string Computer::to_string() const
{
    ostringstream sb;
    sb<<"Manufacturer: "<<manufacturer<<"\nCPU: "<<processor<<"\nRAM: "<<ram_size<<" megabytes"
    <<"\nDisk: "<<disk_size<<" gigabytes";

    return sb.str();
    
}
