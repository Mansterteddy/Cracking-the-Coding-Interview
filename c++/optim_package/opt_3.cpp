//利用牛顿迭代法，求解f(X)=f(x1, x2)=(x1-2)^4+(x1-2x2)^2
//但是该方法要求Hesse矩阵是正定的
#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cassert>

using namespace std;

const int SIZE = 2;
const double ZETA = 0.001;

inline double func(Matrix<double> &X)
{
    assert(SIZE == X.getRows());
    double x1 = X.get(0, 0);
    double x2 = X.get(1, 0);

    return pow(x1-2, 4) + pow(x1-2*x2, 2);
}

inline Matrix<double> gradient(Matrix<double> &X)
{
    assert(SIZE == X.getRows());
    double x1 = X.get(0, 0);
    double x2 = X.get(1, 0);

    Matrix<double> rect(SIZE, 1);
    rect.put(0, 0, 4 * pow(x1-2, 3) + 2 * (x1-2*x2));
    rect.put(1, 0, -4*(x1-2*x2));

    return rect;
}

inline Matrix<double> Hesse(Matrix<double> &X)
{
    Matrix<double> rect(SIZE, SIZE);

    double x1 = X.get(0, 0);
    double x2 = X.get(1, 0);

    rect.put(0, 0, 12 * pow(x1-2, 2) + 2);
    rect.put(0, 1, -4);
    rect.put(1, 0, -4);
    rect.put(1, 1, 8);

    return rect;
}

int main(int argc, char** argv)
{
    Matrix<double> X(SIZE, 1);
    X.put(0, 0, 0);
    X.put(1, 0, 3);

    int iteration = 0;
    double value = func(X);
    double newValue = numeric_limits<double>::max();

    while(++iteration)
    {
        Matrix<double> G = gradient(X);
        Matrix<double> H = Hesse(X);
        Matrix<double> newX = X - H.getInverse() * G;

        cout<<"X = ["<<newX.get(0, 0)<<", "<<newX.get(1, 0)<<"]"<<endl;

        newValue = func(newX);

        if(fabs(newValue-value)<ZETA) 
            break;
        else
        {
            X = newX;
            value = newValue;
        }

        cout<<"This iteration's value is: "<<value<<endl;
    }

    cout<<"Iteration counts: "<<iteration<<endl;
    cout<<"The result is: "<<value<<endl;

    return 0;

}
