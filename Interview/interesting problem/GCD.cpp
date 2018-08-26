//最大公约数

#include <iostream>

using namespace std;

//辗转相除法 a = m * b + c 如果存在d是b和c的最大公约数，那么也就a和b的最大公约数
int GCD(int a, int b)
{
    if( a < b)
    {
        int d = a;
        a = b;
        b = d;
    }
    
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        int c = a % b;
        return GCD(b, c);
    }
}

int main()
{
    cout<<GCD(6, 23)<<endl;
    return 0;
}