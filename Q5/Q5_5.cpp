//Write a function to determine the number of bits required to convert integer A to integer B 
//Input: 31, 14
//Output: 2
#include <iostream>

using namespace std;

int trans(int x, int y)
{
    int res = 0;
    for(int i = 0; i < 32; i++)
    {
        int a = x & 1;
        int b = y & 1;
        if(a != b) res++;
        x = x >> 1;
        y = y >> 1;
    }
    return res;
}

//可以将两个数做异或 再统计其中1的数目
int count_one(int x)
{
    x = (x & (0x55555555)) + ((x>>1) & (0x55555555));
    x = (x & (0x33333333)) + ((x>>2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x>>4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x>>8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x>>16) & (0x0000ffff));

    return x;
}

int convert_num(int a, int b)
{
    return count_one(a^b);
}

int main()
{
    cout<<"Result is: "<<trans(31, 14)<<endl;
    cout<<"Result is: "<<convert_num(31, 14)<<endl;
    return 0;
}