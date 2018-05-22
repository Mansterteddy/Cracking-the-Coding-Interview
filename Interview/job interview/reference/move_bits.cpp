#include <iostream>

using namespace std;

int main()
{
    int a = 3;
    int b = 1;

    int c = a | b;
    cout<<"c: "<<c<<endl;

    int d = a & b;
    cout<<"d: "<<d<<endl;

    int e = a || b;
    cout<<"e: "<<e<<endl;

    int f = a && b;
    cout<<"f: "<<f<<endl;

    int g = ~a;
    cout<<"g: "<<g<<endl;

    //两个值不相同，结果为1。两个值相同，结果为0。
    int h = a^b;
    cout<<"h: "<<h<<endl;

    int i = a >> 2;
    cout<<"i: "<<i<<endl;

    int j = i << 2;
    cout<<"j: "<<j<<endl;

    int k = !a;
    cout<<"k: "<<k<<endl;

    int l = -1;

    int m = l >> 2;
    cout<<"m: "<<m<<endl;

    int n = l << 2;
    cout<<"n: "<<n<<endl;

    return 0;
}