//黄金分割的定义是：将整体一分为二，较大部分与整体的比值 等于较小部分与较大部分的比值
//适用于寻找单峰函数最小值的问题
//求解f(x)=x^2 - 10x + 36 在[1, 10]上的极小值

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

double func(double x)
{
    return x*x-10*x+36;
}

int main()
{
    double zeta = 0.001;
    double a = 1.0, b = 10.0;
    double t1 = a - 1;
    double t2 = b + 1;
    double v1 = 0.0;
    double v2 = 0.0;
    double min_value = INT_MAX;
    int iteration = 0;

    while(++iteration)
    {
        if(t1 == a-1)
        {
            t1 = a + 0.382 * (b-a);
            v1 = func(t1);
        }
        if(t2 == b+1)
        {
            t2 = a + 0.618 * (b-a);
            v2 = func(t2);
        }
        if(v1 < v2)
        {
            min_value = v1;
            b = t2;
            t2 = t1;
            v2 = v1;
            t1 = a-1;
        }
        else
        {
            min_value = v2;
            a = t1;
            t1 = t2;
            v1 = v2;
            t2 = b+1;
        }
        if(abs(b-a)<zeta)
            break;

        cout<<"Current min: "<<min_value<<endl;

    }

    cout<<"Iteration counts: "<<iteration<<endl;
    cout<<"Min value: "<<min_value<<endl;

    return 0;
}
