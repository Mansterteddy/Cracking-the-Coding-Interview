#include "Rectangle.h"
#include "Circle.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

Shape* get_shape()
{
    char fig_type;
    cout<<"Enter C for circle\nEnter R for rectangle\n";
    cin>>fig_type;
    fig_type = tolower(fig_type);

    if(fig_type == 'r')
    {
        return new Rectangle();
    }
    else if(fig_type == 'c')
    {
        return new Circle();
    }
    else
    {
        return NULL;
    }
}

void display_result(double area, double perim)
{
    cout<<"The area is "<<area<<"\nThe perimeter is "<<perim<<endl;
}

int main()
{
    Shape* my_shape;
    double perimeter;
    double area;
    my_shape = get_shape();
    my_shape->read_shape_data();
    perimeter = my_shape->compute_perimeter();
    area = my_shape->compute_area();
    display_result(area, perimeter);

    delete my_shape;

    return 0;
}