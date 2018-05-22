#include "Lap_Top.h"
#include <sstream>

using std::endl;
using std::string;
using std::ostringstream;

string Lap_Top::to_string() const
{
    ostringstream sb;
    sb<<"For Laptop Manufacturer: "<<manufacturer<<"\nCPU: "<<processor<<"\nRAM: "<<ram_size<<" megabytes"
    <<"\nDisk: "<<disk_size<<" gigabytes"<<"\nScreen Size: "<<screen_size<<"\nWeight: "<<weight<<endl;

    return sb.str();
}