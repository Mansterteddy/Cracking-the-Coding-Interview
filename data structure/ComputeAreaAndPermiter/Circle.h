#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public virtual Shape
{
    public:
        Circle(): radius(0) {}
        Circle(int the_radius) : radius(the_radius){}
        int get_radius() const {return radius;}
        double compute_area() const;
        double compute_perimeter() const;
        void read_shape_data();
        std::string to_string() const;

    private:
        int radius;
};

#endif