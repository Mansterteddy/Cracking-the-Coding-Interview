#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double d = 12345.67890;
    cout<<setw(10)<<"precesion "<<setw(18)<<"general "<<setw(18)
    <<"fixed"<<setw(18)<<"scientific\n";
    for(int i = 10; i >= 0; i--)
    {
        cout<<setprecision(i);
        cout<<setw(10)<<i;
        cout<<resetiosflags(ios_base::fixed | ios_base::scientific);
        cout<<setw(18)<<d;
        cout<<fixed<<setw(18)<<d;
        cout<<scientific<<setw(18)<<d<<endl;
    }
}