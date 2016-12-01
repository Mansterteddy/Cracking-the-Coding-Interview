#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"Using showpoint the number 12345.0 "
    <<" is output as "<<showpoint<<12345.0
    <<"\nand using noshowpoint it is output as "
    <<noshowpoint<<12345.0<<endl;

    cout<<"Using setw(10) the number 12345 appears as "
    <<setw(10)<<12345<<endl;

    cout<<"Using setfill('0') and setw(10) 12345 appears as "
    <<setfill('0')<<setw(10)<<12345<<endl;

    cout<<setfill(' ');

    cout<<"Using left, setfill('*') and setw(10) 12345 appear as "
    <<left<<setfill('*')<<setw(10)<<12345<<endl;

    cout<<right<<setfill(' ');
}