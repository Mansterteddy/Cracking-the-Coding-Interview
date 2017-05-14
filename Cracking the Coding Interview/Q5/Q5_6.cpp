//Write a program to swap odd and even bits in an integer with as few instructions as possible
//(e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)
#include <iostream>

using namespace std;

//分别将整数的奇数位和偶数位提取出来，然后移动位置取或即可

int swap_bits(int x)
{
    return ((x & 0x55555555)<<1) | ((x>>1) & (0x55555555));
}

int main()
{
    cout<<"Result is: "<<swap_bits(5)<<endl;
    return 0;
}