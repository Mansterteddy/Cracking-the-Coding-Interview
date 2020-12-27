#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = 3;

    int c = a > b ? a : 3;
    cout<<"c: "<<c<<endl;

    int d = min(a, b);
    cout<<"d: "<<d<<endl;

    int e = max(a, b);
    cout<<"e: "<<e<<endl;

    return 0;
}