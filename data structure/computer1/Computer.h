#ifndef COMPUTER_H_
#define COMPUTER_H_

#include <string>

class Computer
{
    protected:
        std::string manufacturer;
        std::string processor;
        int ram_size;
        int disk_size;

    public:

        Computer(const std::string& man, const std::string proc, int ram, int disk) : manufacturer(man), processor(proc),
        ram_size(ram), disk_size(disk) {}

        int get_ram_size() const {return ram_size;}

        int get_disk_size() const {return disk_size;}

        virtual std::string to_string() const;
};

#endif