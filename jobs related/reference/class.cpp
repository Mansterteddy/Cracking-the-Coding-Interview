#include <string>
#include <sstream>
#include <iostream>

using std::cout;

class Address
{
    public:
        Address(const std::string& hn, const std::string& str,
                const std::string muni, const std::string& stpro,
                const std::string& pc): house_number(hn), street_name(str), 
                municipality(muni), state_or_province(stpro), postal_code(pc) {}

        virtual std::string to_string() const = 0;

        virtual ~Address() {}

        void set_house_number(std::string new_house_number)
        {
            house_number = new_house_number;
        }

    protected:
        std::string house_number;
        std::string street_name;
        std::string municipality;
        std::string state_or_province;
        std::string postal_code;
};

class German_Address : public Address
{
    public:
        German_Address(const std::string& hn, const std::string& str, 
            const std::string& muni, const std::string& pc) : Address(hn, str, muni, "", pc) {}

        std::string to_string() const;
};

std::string German_Address::to_string() const 
{
  std::ostringstream result;
  result << street_name << " " << house_number << "\n"
         << postal_code << " " << municipality << "\n"
         << "Germany\n";
  return result.str();
}

int main()
{
    Address* add2 = new German_Address("345", "Bahnhofstr", 
                                     "Jedenstadt", "D-99999");

  // cout << add1->to_string() << "\n\n";
    cout << add2->to_string() << "\n\n";

    return 0;
}

