#include "Address.h"
#include <sstream>

using std::string;
using std::ostringstream;

string US_Address::to_string() const
{
    ostringstream result;
    result<<street_name<<" "<<house_number<<"\n"
    <<postal_code<<" "<<municipality<<" "<<state_or_province<<"\n"<<"USA\n";

    return result.str();
}