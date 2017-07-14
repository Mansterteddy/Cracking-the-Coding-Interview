#ifndef TWODARRAY_H_
#define TWODARRAY_H_

#include <cstddef>

/** Class to define a two dimensional array whose dimensions
    can be declared at run time.
*/
template<typename Item_Type>
  class TwoDArray {

  public:

  /** Construct a TwoDArray with n rows and m columns. */
  TwoDArray(size_t n, size_t m) : 
    num_rows(n), num_cols(m), data(new Item_Type[n * m]) {}

  /** Destructor. */
  ~TwoDArray() { delete data; }

  /** Access a row. */
  Item_Type* operator[](size_t i) {
    return data + num_cols * i;
  }

  const Item_Type* operator[](size_t i) const {
    return data + num_cols * i;
  }

  /** Get the number of rows. */
  size_t get_num_rows() const {return num_rows;}

  /** Get the number of columns. */
  size_t get_num_cols() const {return num_cols;}

  private:

  /** Number of rows */
  size_t num_rows;
  /** Number of columns */
  size_t num_cols;
  /** The data array */
  Item_Type* data;

  // Prohibit copy and assignment
  TwoDArray(const TwoDArray&);
  TwoDArray& operator=(const TwoDArray&);

};
