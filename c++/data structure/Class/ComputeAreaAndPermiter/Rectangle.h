#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public virtual Shape
{
    public:
        Rectangle() : width(0), height(0) {}
        Rectangle(int the_width, int the_height) : width(the_width), height(the_height) {}
        int get_width() const {return width;}
        int get_height() const {return height;}
        double compute_area() const;
        double compute_perimeter() const;
        void read_shape_data();
        std::string to_string() const; 

    protected:
        int width;
        int height;
};

#endif