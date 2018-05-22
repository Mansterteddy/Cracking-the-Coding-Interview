//最速下降法
//利用泰勒二阶展开，求解最佳步长，这个过程中要用到Hesse矩阵
//f(x1, x2) = x1 * x1 + 4 * x2 * x2

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

    return x1 * x1 + 4 * x2 * x2;
}


inline Matrix<double> gradient(Matrix<double> &X)
{
    assert(SIZE == X.getRows());

    double x1 = X.get(0, 0);
    double x2 = X.get(1, 0);
    Matrix<double> rect(SIZE, 1);
    rect.put(0, 0, 2 * x1);
    rect.put(1, 0, 8 * x2);

    return rect;
}

inline Matrix<double> Hesse(Matrix<double> &X)
{
    Matrix<double> rect(SIZE, SIZE);
    rect.put(0, 0, 2);
    rect.put(0, 1, 0);
    rect.put(1, 0, 0);
    rect.put(1, 1, 8);
    
    return rect;
}

int main(int argc, char** argv)
{
    Matrix<double> X(SIZE, 1);
    X.put(0, 0, 1);
    X.put(1, 0, 1);

    int iteration = 0;
    double value = func(X);
    double newValue = numeric_limits<double>::max();

    while(++iteration)
    {
        Matrix<double> G = gradient(X);
        double factor = ((G.getTranspose() * G).get(0, 0)) / ((G.getTranspose() * Hesse(X) * G).get(0, 0));

        for(int i = 0; i < G.getRows(); ++i)
        {
            for(int j = 0; j < G.getColumns(); ++j)
            {
                G.put(i, j, G.get(i, j) * factor);
            }
        }

        Matrix<double> newX = X - G;

        newValue = func(newX);

        if(fabs(newValue - value) < ZETA)
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
