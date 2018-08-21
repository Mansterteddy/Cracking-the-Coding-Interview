//最大连续子序列和

#include <iostream>
#include <algorithm>

using namespace std;

//可以使用递归，对大小为n的数列，分别要前n/2，后n/2，和中间部分。中间部分分为两块：从前半部分某个元素到[n/2]的最大子序列和以及从[n/2]到后半部分的最大子序列和
//A[n] = max(arr[n], A[n-1] + arr[n]) Max = max(A[n])
/*
对于第n位，以n为最后一位的最大子序列和等于以第n-1项为末尾的最大子序列和加上当前位置 或者以当前位置为起点，另起一个子序列
关键在于在求以第n位为最后一项的最大子序列 如果以第n-1项为末尾的最大子序列和小于0，那么不如只有第n项一个元素的子序列
*/

int DP_2(int *arr, int size)
{
    int *A = new int[size];
    int *S = new int[size];
    int *pre = new int[size];

    int max_res;
    int max_res_pos;
    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            S[i] = max(0, arr[i]);
            pre[i] = -1;
            max_res = S[i];
            max_res_pos = i;
        }
        else
        {
            if(S[i-1] + arr[i] > arr[i])
            {
                S[i] = S[i-1] + arr[i];
                pre[i] = i-1;
            }
            else
            {
                S[i] = arr[i];
                pre[i] = -1;
            }
            if(S[i] > max_res) 
            {
                max_res = S[i];
                max_res_pos = i;
            }
        }
    }

    do
    {
        cout<<arr[max_res_pos]<<" ";
        max_res_pos = pre[max_res_pos];
    }while(max_res_pos != -1);
    cout<<endl;
    return max_res;
}

int main()
{
    int array[] = {1, 5, -3, 4, -3, 3};
    int len = sizeof(array) / sizeof(array[0]);
    cout<<DP_2(array, len)<<endl;
    return 0;
}