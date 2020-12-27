#include <iostream>

using namespace std;

int main()
{
    int *a = new int[8];

    for(int i = 0; i < 8; ++i)
    {
        a[i] = i;
    }
    
    for(int i = 0; i < 8; ++i)
    {
        cout<<a[i]<<" ";
    }

    delete []a;

    return 0;
}