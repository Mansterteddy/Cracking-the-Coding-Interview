//Write an algorithm such that if an elements in an M*N matrix is 0, its entire row and column is set to 0.

#include <iostream>

using namespace std;

//声明未知长度的数组 应当使用动态内存分配 malloc 或者new
void replace(int (*a)[4], int length)
{
    int b[4] = {0, 0, 0, 0};
    int *c;
    c = (int*) malloc(sizeof(int) * length);
    //c = new int[length];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(a[i][j] == 0)
            {
                b[j] = 1;
                c[i] = 1;
            }
        }
    }
    
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if (b[j] == 1 || c[i] == 1)
            {
                a[i][j] = 0;
            }
        }
    }
}


int main()
{
    int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 0}, {9, 0, 11, 12}};
    int length = sizeof(a) / sizeof(a[0]);
    replace(a, length);
    
    for(int i = 0; i< length; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    
    return 1;
    
}
