#ifndef LAP_TOP_H_
#define LAP_TOP_H_

#include "Computer.h"

/** Class to represent a laptop computer */

class Lap_Top : public Computer {
  public:
    // Functions
    /** Construct a Lap_Top object.
        @param man The manufacturer
        @param proc The processor
        @param ram The RAM size
        @param disk The disk size
        @param screen The screen size
        @param wei The weight
    */
    Lap_Top(const std::string& man, const std::string& proc, 
            int ram, int disk, double screen, double wei) :
      Computer(man, proc, ram, disk), screen_size(screen), weight(wei) {}
  
    /** Construct a Lap_Top object with a default manufacturer. */
Lap_Top(const std::string& proc, int ram, int disk, 
        double screen, double wei) : 
  Computer(DEFAULT_LT_MAN, proc, ram, disk), screen_size(screen),
           weight(wei) {}

    /** Generate a string representation of a Lap_Top object. */
    std::string to_string();

  private:
    // Data Fields
    static const char* DEFAULT_LT_MAN;
    double screen_size;
    double weight;
};

#endif
