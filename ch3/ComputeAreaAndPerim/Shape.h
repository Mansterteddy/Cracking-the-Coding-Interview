#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

/** Declaration file for the abstract class Shape. */
class Shape {
  public:
    virtual double compute_area() const  = 0;
    virtual double compute_perimeter() const = 0;
    virtual void read_shape_data() = 0;
    virtual std::string to_string() const = 0;
    virtual ~Shape() {}
};

#endif
