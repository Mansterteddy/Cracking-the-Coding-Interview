#include <iostream>

using namespace std;

int main()
{
    int m[4][4];
    int k = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m[j][i] = k++;
        }
    }

    int* p = &m[0][0];

    for(int i = 0; i < 16; ++i)
    {
        cout<<*p++<<" ";
    }
    cout<<endl;
}