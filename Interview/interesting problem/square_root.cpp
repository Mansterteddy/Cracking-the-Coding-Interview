//Fast Inverse Square Root Algorithm, compared with standard function
//主要方法包括：二分法、牛顿迭代法和梯度下降法。

#include <iostream>
#include <cmath>

using namespace std;

float InvSqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x; //get bits for floating value
    i = 0x5f3759df - (i>>1); //gives initial guess y0
    x = *(float*)&i; //convert bits back to float
    x = x * (1.5f - xhalf * x * x); //Newton step, repeating increases accuracy
    return x;
}

float InvSqrt_1(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i>>1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

//只要保证最后的倒数根在y_pre到y_back这个区间就可以使用二分法来做
float InvSqrt_2(float x)
{
    float y = 0;
    float eps = 0.01f; 
    float y_back = 1.0;
    float y_pre = 0.0;
    while(abs(1.0 / x - (y * y)) > eps)
    {
        y = (y_back + y_pre) / 2.0;
        if(1.0 / x > y * y)
        {
            y_pre = y;
        }
        else
        {
            y_back = y;
        }
    }
    return y;
}

float InvSqrt_3(float x)
{
    float y = 10.0;//初始值
    float alpha = 0.01;
    float eps = 0.01;
    while(abs(1.0 / x - y * y) > eps)
    {
        y = y - 2.0 * alpha * y;
    }
    return y;
}

float InvSqrt_4(float x)
{
    float num = 1.0 / x;
    float y = 10.0;//初始值
    float eps = 0.01;
    while(abs(1.0 / x - y * y) > eps)
    {
        y = 0.5 * y + num / (2 * y);
    }
    return y;
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
    float w = InvSqrt_1(x);
    cout<<"Square Root 3: "<<w<<endl;
    cout<<"Multiply Result 3:"<<w * w<<endl;
    float v = InvSqrt_3(x);
    cout<<"Square Root 5: "<<v<<endl;
    cout<<"Multiply Result 5: "<<v * v<<endl;
    float u = InvSqrt_2(x);
    cout<<"Square Root 6: "<<u<<endl;
    cout<<"Multiply Result 6: "<<u * u<<endl;
    float t = InvSqrt_4(x);
    cout<<"Square Root 7: "<<t<<endl;
    cout<<"Multiply Result 7: "<<t * t<<endl;
    return 0;
}