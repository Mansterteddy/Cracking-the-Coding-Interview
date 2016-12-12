/** Implementation of Rectangle class. */
#include "Rectangle.h"

#include <sstream>
#include <iostream>
#include <istream>
#include <ostream>

using std::string;
using std::ostringstream;
using std::cin;
using std::cout;

double Rectangle::compute_area() const {
  return width * height;
}

double Rectangle::compute_perimeter() const {
  return 2 * width + 2 * height;
}

void Rectangle::read_shape_data() {
  cout << "Enter the width of the rectangle: ";
  cin >> width;
  cout << "Enter the height of the rectangle: ";
  cin >> height;
}

string Rectangle::to_string() const {
  ostringstream result;
  result << "Rectangle: width is " << width
         << ", height is " << height;
  return result.str();
}
