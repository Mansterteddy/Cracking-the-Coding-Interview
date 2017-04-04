#ifndef SHAPE__H__
#define SHAPE__H__

#include <string>

class Shape
{
    public:

        virtual double compute_area() const = 0;
        virtual double compute_perimeter() const = 0;
        virtual void read_shape_data() = 0;
        virtual std::string to_string() const = 0;
        virtual ~Shape(){}
};

#endif

