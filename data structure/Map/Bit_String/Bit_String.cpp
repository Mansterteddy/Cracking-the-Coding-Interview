#include "Bit_String.h"
#include <istream>
#include <ostream>


/** Access a selected bit
    @param i The index of the selected bit
    @return true if the selected bit is a 1
*/
bool Bit_String::operator[](size_t i) const {
  if (i >= num_bits) {
    throw std::out_of_range("Bit_String operator[]");
  }
  return (the_data[index(i)] & mask(i)) != 0;
}

/** Append a value to the end of the string
    @param newBit The value to append true for 1 and
    false for zero
*/
Bit_String& Bit_String::append(bool new_bit) {
  if (index(num_bits) == the_data.size())
    the_data.push_back(0);
  if (new_bit) {
    the_data[index(num_bits)] |= mask(num_bits);
  }
  num_bits++;
  return *this;
}

/** A method to append one BitString onto another
    @param left BitString
    @param right The righ BitString
    @post The left BitString is modified to the
    result
*/
Bit_String& Bit_String::operator+=(const Bit_String& right) {
  for (size_t i = 0; i < right.size(); i++) {
      append(right[i]);
  }
  return *this;
}

/** Return a String representation of this BitString
    where each 1 is a '1' and each 0 is a '0'
    @return A String representation of this BitString.
*/
std::string Bit_String::to_string() {
  std::string result;
  for (size_t i = 0; i < num_bits; i++) {
    if ((*this)[i]) {
      result += "1";
    }
    else {
      result += "0";
    }
  }
  return result;
}

/** A method to append one BitString onto another
    @param left BitString
    @param right The righ BitString
    @post The left BitString is modified to the
    result
*/
Bit_String operator+(const Bit_String& left, const Bit_String& right) {
  Bit_String result(left);
  return result += right;
}

/** Write this Bit_String to the specified ostream
    without formatting */
std::ostream& Bit_String::write(std::ostream& out) const {
  out << num_bits;
  for (std::vector<char>::const_iterator itr = the_data.begin();
       itr != the_data.end(); ++itr)
    out << *itr;
  return out;
}

/** Read a Bit_String from the specified istream
    without formatting.  The istream must be positioned
    at the beginning of the results of a previous write.
*/
Bit_String Bit_String::read(std::istream& in) {
  Bit_String result;
  in >> result.num_bits;
  size_t num_bytes = (result.num_bits + 7) / 8;
  char c;
  for (size_t i = 0; i < num_bytes; i++) {
    in.get(c);
    result.the_data.push_back(c);
  }
  return result;
}
