/*
给定一个正数，检查该数字是否是回文数。这道题很简单，最开始我考虑的是设置两个指针，
从前向后和从后向前遍历，直到相遇。
但是只要观察问题性质就好了，回文数的性质是从前到后，和从后到前，都是一样的。
*/

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