//Implementation of circle class
#include "Circle.h"
#include <sstream>
#include <iostream>
#include <istream>
#include <ostream>

using std::string;
using std::ostringstream;
using std::cin;
using std::cout;
using std::endl;

#define PI 3.1415926

double Circle::compute_area() const
{
    return PI * radius * radius;
}

double Circle::compute_perimeter() const
{
    return 2 * PI * radius;
}

void Circle::read_shape_data()
{
    cout << "Enter the radius of the circle: ";
    cin >> radius;
}

std::string Circle::to_string() const
{
    ostringstream result;
    result<<"The radius of circle is: "<<radius<<endl;


    return result.str();
}