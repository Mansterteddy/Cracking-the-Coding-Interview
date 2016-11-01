//实现bit-map算法
//实现分段式的bit-map算法
#include <iostream>
#include <fstream>

using namespace std;

void bit_map_1()
{
    int int_len = sizeof(int) * 8;
    cout<<"int_len:"<<sizeof(int)<<endl;
    int a[] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 12, 30, 34};
    int b[] = {0, 0};
    int length = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < length; i++)
    {
        int j = a[i] / int_len;
        b[j] |= 1<<(a[i] % int_len);
    }
    for(int i = 0; i < (sizeof(b) / sizeof(b[0])); i++)
    {
        for(int j = 0; j < int_len; j++)
        {
            int t = b[i] % 2;
            b[i] /= 2;
            if(t == 0)
            {
                cout<<"Lack: "<< i * int_len + j<<endl;
            }
        }
    }

}

int main()
{
    bit_map_1();
    return 0;
}