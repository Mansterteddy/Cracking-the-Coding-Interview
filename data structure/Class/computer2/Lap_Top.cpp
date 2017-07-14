/** Implementation of the Lap_Top class. */
#include "Lap_Top.h"
#include <sstream>

using std::string;
using std::ostringstream;

string Lap_Top::to_string() {
  ostringstream sb;
  sb << Computer::to_string()
     << "\nScreen Size: " << screen_size
     << "\nWeight: " << weight;
  return sb.str();
}

const char* Lap_Top::DEFAULT_LT_MAN = "MyBrand";
