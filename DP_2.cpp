//最大连续子序列和

#include <iostream>
#include <algorithm>

using namespace std;

//可以使用递归，对大小为n的数列，分别要前n/2，后n/2，和中间部分。中间部分分为两块：从前半部分某个元素到[n/2]的最大子序列和以及从[n/2]到后半部分的最大子序列和
//A[n] = max(A[n-1], S[n-1] + arr[n])
/*
对于第n位，最大子序列和等于前n-1位最大子序列和 或者是以第n项为末尾的最大子序列和
因此在这里我们设计一个S，S[n]为以n为结尾的最大子序列和，要么为0（代表空序列），要么为S[n-1] + arr[n]
*/

int DP_2(int *arr, int size)
{
    int *A = new int[size];
    int *S = new int[size];

    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            S[i] = max(0, arr[i]);
        }
        else
        {
            if(S[i - 1] <= 0) S[i] = arr[i];
            else S[i] = max(S[i-1] +arr[i], 0);
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(i == 0) A[i] = arr[i];
        else
        {
            A[i] = max(A[i-1], max(S[i-1] + arr[i], arr[i]));
        }
    }

    return A[size-1];
}

int main()
{
    int array[] = {-1, 5, -3, 4, -3, 4};
    int len = sizeof(array) / sizeof(array[0]);
    cout<<DP_2(array, len)<<endl;
    return 0;
}