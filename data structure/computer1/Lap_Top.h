#ifndef LAP_TOP_H_
#define LAP_TOP_H_

#include "Computer.h"

class Lap_Top : public Computer
{
    public:
        Lap_Top(const std::string& man, const std::string& proc, int ram, int disk, double screen, double wei):
        Computer(man, proc, ram, disk), screen_size(screen), weight(wei) {}

        std::string to_string() const;

    private:
        double screen_size;
        double weight;
};

#endif