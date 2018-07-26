//给定一个整数，判断该数字是否是回文数。

#include <iostream>
#include <cmath>

using namespace std;

int reverse_num(int a)
{
    int res = 0;
    while(a != 0)
    {
        int residual = a % 10;
        a = a / 10;
        res *= 10;
        res += residual;
        cout<<"res: "<<res<<endl;
    }

    return res;
}

int main()
{
    int num = -123;
    num = abs(num);

    int reverse = reverse_num(num);

    if(reverse == num)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }


    return 0;
}