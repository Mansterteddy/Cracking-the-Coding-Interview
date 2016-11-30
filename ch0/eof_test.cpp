#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    cout<<"Enter a set of numbers. Enter ^Z (Windows)"
    <<"or ^D(Unix) to terminate\n";

    int n = 0;
    int sum = 0;
    int i;

    while(cin >> i)
    {
        n++;
        sum += i;
    }

    if(cin.bad())
    {
        cout<<"There was an unrecoverable io error\n";
        return 1;
    }
    
    //crtl + z is cin.eof()
    if(cin.eof())
    {
        cout<<"End of file reached\n";
        cout<<"You entered "<<n<<" numbers\n";
        cout<<"Their sum is "<<sum<<endl;
    }
    else if(cin.bad())
    {
        cout<<"Unrecoverable i/o error on cin\n";
        return 1;
    }
    else
    {
        cout<<"The last entry was not a valid number\n";
        return 1;
    }

    return 0;
}