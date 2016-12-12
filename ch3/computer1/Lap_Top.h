#ifndef LAP_TOP_H_
#define LAP_TOP_H_

#include "Computer.h"

/** Class to represent a lap top computer */

class Lap_Top : public Computer
{
 public:
  //Funcitons
  /** Consruct a Lap_Top object
      @param man The manufacturer
      @param proc The processor
      @param ram The ram size
      @param disk The disk size
      @param screen The screen size
      @param wei The weight
  */

Lap_Top(const std::string& man, const std::string& proc, 
        int ram, int disk, double screen, double wei) :
  Computer(man, proc, ram, disk), screen_size(screen), weight(wei) {}



private:
  // Data Fields
  double screen_size;
  double weight;
};

#endif
