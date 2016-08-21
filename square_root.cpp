//Fast Inverse Square Root Algorithm, compared with standard function
#include <iostream>
#include "math.h"

using namespace std;

float InvSqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i; 
    x = x * (1.5f - xhalf * x * x);
    return x;
}

int main()
{
    float x = 4.99;
    float y = (1.0 / sqrt(x));
    cout<<"Square Root 1: "<<y<<endl;
    cout<<"Multiply Result 1:"<<y * y<<endl;
    float z = InvSqrt(x);
    cout<<"Square Root 2: "<<z<<endl;
    cout<<"Multiply Result 2:"<<z * z<<endl;
    return 0;
}