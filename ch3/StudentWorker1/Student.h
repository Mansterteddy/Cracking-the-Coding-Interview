#ifndef STUDENT_H_
#define STUDENT_H_

#include "Address.h"
#include <string>

#ifdef major
#undef major
#endif

class Student
{
 public:
  /** Create an empty Student */
  Student() {}
  /** Create a Student from the given parameters
      @param the_name The employee's name
      @param the_address Pointer to Employee's address
      @param the_major The Student's major
  */
  Student(const std::string& the_name, 
                    Address* the_address,
                    const std::string& the_major)
    : name(the_name), p_address(the_address),
        major(the_major), gpa(0.0) {}

  /** The copy constructor */
  Student(const Student& other);

  /** The assignment operator */
  Student& operator=(const Student& other);

  /** The destructor */
  virtual ~Student() { delete p_address; }

  /** Update Student's house number */
  void set_house_number (std::string new_house_number) {
    p_address->set_house_number(new_house_number);
  }

  /** Get the Student's gpa */
  double get_gpa() const {return gpa;}

  /** Set Student's gpa
   */
  void set_gpa(double new_gpa) { gpa = new_gpa; }

  /** Return String Representation of Student */
  std::string to_string() const;

  void swap(Student& other)
    {
      std::swap(name, other.name);
      std::swap(p_address, other.p_address);
      std::swap(major, other.major);
      std::swap(gpa, other.gpa);
    }

 protected:
  std::string name;
  Address* p_address;
  std::string major;
  double gpa;
};

inline
void swap(Student& s1, Student& s2)
{
  s1.swap(s2);
}

#endif
