#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>

class Address
{
    public:
        Address(const std::string& hn, const std::string& str, const std::string muni, const std::string& stpro, const std::string& pc):
        house_number(hn), street_name(str), municipality(muni), state_or_province(stpro), postal_code(pc) {}

        virtual std::string to_string() const = 0;

        virtual ~Address() {}

        void set_house_number(std::string new_house_number)
        {
            house_number = new_house_number;
        }

        virtual Address* clone() const = 0;
    

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
        German_Address(const std::string& hn, const std::string& str, const std::string& muni, const std::string& pc) :
        Address(hn, str, muni, "", pc) {}

        std::string to_string() const;

        Address* clone() const {return new German_Address(*this);}
};

#endif