#ifndef COMPUTER_H_
#define COMPUTER_H_

#include <string>

/** Class that represents a computer.*/
class Computer {
  // Data Fields
 protected:
  std::string manufacturer;
  std::string processor;
  int ram_size;
  int disk_size;

 public:
  // Functions
  /** Initializes a Computer object with all properties specified.
      @param man The computer manufacturer
      @param proc The processor type
      @param ram The RAM size
      @param disk The disk size
  */
  Computer(const std::string& man, 
	   const std::string proc, 
	   int ram, int disk) :
    manufacturer(man), processor(proc), 
    ram_size(ram), disk_size(disk) {}

  /** virtual destructor to avoid warning messages */
  virtual ~Computer() {}

  int get_ram_size() const { return ram_size; }
  
  int get_disk_size() const { return disk_size; }

  // Insert other accessor and modifier functions here.
  virtual std::string to_string() const;

};

#endif
