//Program to demonstrate different floating-point output formats

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double d = 1234567890.0;

    cout<<setw(18)<<"general"<<setw(18)<<"fixed"<<setw(18)<<"scientific\n";
    for(int i = 0; i < 20; i++)
    {
        cout<<resetiosflags(ios_base::fixed | ios_base::scientific);
        cout<<setw(18)<<d;
        cout<<fixed<<setw(18)<<d;
        cout<<scientific<<setw(18)<<d<<endl;
        d /= 10;
    }
}