/** Implementation file for the class German_Address */
#include "Address.h"
#include <sstream>
using std::string;
using std::ostringstream;

string German_Address::to_string() const 
{
  ostringstream result;
  result << street_name << " " << house_number << "\n"
         << postal_code << " " << municipality << "\n"
         << "Germany\n";
  return result.str();
}
