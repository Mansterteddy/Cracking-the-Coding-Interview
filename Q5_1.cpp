//You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
//Write a method to set all bits between i and j in N equals to M 
//(e.g., M becomes a substring of N located at i and starting at j). 
//EXAMPLE:
//Input: N = 10000000000, M = 10101, i = 2, j = 6
//Output: N = 10001010100

#include <iostream>
#include "math.h"

using namespace std;

long long int replace_number(long long int N, long long int M, int i, int j)
{
    long long int res = 0;
    int cur = 0;
    while(N / 10 != 0 || N % 10 != 0)
    {
        int rd = N % 10;
        res = res + pow(10, cur) * rd;
        if(cur >= i && cur <= j)
        {
            int tmp = M % 10;
            res = res - pow(10, cur) * rd;
            res = res + pow(10, cur) * tmp;
            M = M / 10;
        }
        N = N / 10;
        cur++;
    }
    //int rd = N;
    //cout<<"rd: "<<rd<<" "<<cur<<endl;
    //res = res + pow(10, cur) * rd;
    return res;
}

//有符号数，最高位为1，右移若干位到达位置i，最高位和第i位之间全是1
//无符号数，最高位为1，右移若干位到达位置1，最高位和第i位之间全是0
//无论是有符号数还是无符号数，左移若干位，新出现的都是0
//int最大值 0后面跟着31个1
//int最小值 1后面跟着31个0
//unsigned int最大值 32个1
//unsigned int最小值 0

int update_bits(int n, int m, int i, int j)
{
    int ret = (1<<i) - 1;
    //保留了后面的几位
    ret &= n;
    //n>>(j+1)<<(j+1)置空j后面的位置 然后i到j的位置填充为m 最后ret是后面的位置 取并集即可
    return ((n >> (j + 1)) << (j + 1)) | (m<<i) | ret;
}

int update_bits_1(int n, int m, int i, int j)
{
    int max = ~0;
    //j以前的全是1
    int left = max - ((1<<j + 1) - 1);
    //i以后的全是1
    int right = ((i<<i) - 1);
    int mask = left | right;
    return (n & mask) | (m<<i);
}

int main()
{
    long long int N = 10000000000;
    long long int M = 10101;
    int i = 2;
    int j = 6;
    cout<<"N: "<<N<<endl;
    long long int res = replace_number(N, M, i, j);
    cout<<"Result: "<<res<<endl;

    int n = 1<<10;
    int m = 21;
    int res_1 = update_bits(n, m, i, j);
    cout<<"Result 1: "<<res_1<<endl;

    int res_2 = update_bits(n, m, i, j);
    cout<<"Result 2: "<<res_2<<endl;
    return 0;
}