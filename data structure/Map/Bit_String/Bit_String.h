#ifndef BIT_STRING_H_
#define BIT_STRING_H_

#include <vector>
#include <iosfwd>
#include <stdexcept>

/** A class to represent a string of bits. This class is like
 *  the string class except that the contents is a sequence of 0's 
 *  and 1's. BitSrings are are varying length.
 *  @author Koffman and Wolfgang
 */

class Bit_String {

 public:
  
  /** Construct an empty Bit_String 
   */
  Bit_String() : num_bits(0) {}

  /** Access a selected bit
      @param i The index of the selected bit
      @return true if the selected bit is a 1
   */
  bool operator[](size_t i) const;

  /** Append a value to the end of the string
      @param newBit The value to append true for 1 and
      false for zero
  */
  Bit_String& append(bool new_bit);
  
  /** A method to append one BitString onto another
      @param left BitString
      @param right The righ BitString
      @post The left BitString is modified to the
      result
   */
  Bit_String& operator+=(const Bit_String& right);
  
  /** Return a String representation of this BitString
      where each 1 is a '1' and each 0 is a '0'
      @return A String representation of this BitString.
  */
  std::string to_string();
  
  /** Return the size of this BitString
      @return The size of this BitString
  */
  size_t size() const {
    return num_bits;
  }
  
  /** Write this Bit_String to the specified ostream
      without formatting */
  std::ostream& write(std::ostream& out) const;

  /** Read a Bit_String from the specified istream
      without formatting.  The istream must be positioned
      at the beginning of the results of a previous write.
  */
  static Bit_String read(std::istream& in);

 private:

  /** Vector of char to hold the data */
  std::vector<char> the_data;

  /** Current number of meaningful bits */
  size_t num_bits;

  /** Create a mask for the selected bit
      @param i The index of the selected bit
      @return A mask with a 1 bit set in the
      appropriate bit
  */
  char mask(size_t i) const {
    int r = i % 8;
    return 1 << r;
  }
  
  /** Determine the index of the byte that contains
      the selected bit
      @param i The index of the selected bit
      @return The index of the byte that contains the
      selected bit.
  */
  size_t index(size_t i) const {
    return i / 8;
  }
  
};

/** A method to append one BitString onto another
    @param left BitString
    @param right The righ BitString
    @post The left BitString is modified to the
    result
*/
Bit_String operator+(const Bit_String& left, const Bit_String& right);

#endif
