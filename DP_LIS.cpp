//最长递增子序列
//解法1：DP
//解法2：排序+LCS算法
#include <iostream>
#include <algorithm>
using namespace std;

int dp_1(int *a, int len)
{
    int* d = new int[len];
    int* index = new int[len];

    for(int i = 0; i < len; i++)
    {
        index[i] = -1;
    }

    d[0] = 1;
    
    for(int i = 1; i < len; i++)
    {
        int max = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
            if(max < d[j] + 1)
                {
                 max = d[j] + 1;
                 index[i] = j;
                }
            }
        }
        d[i] = max;
    }

    int res = d[0];
    int pos = -1;
    for(int i = 1; i < len; i++)
    {
        if(res < d[i]) 
        {
            res = d[i];
            pos = i;
        }
    }

    while(pos != -1)
    {
        cout<<a[pos]<<" ";
        pos = index[pos];
    }

    return res;
}

//先将数组排列，然后寻找LCS
int dp_2(int *a, int len)
{
    int *b = new int[len];
    for(int i = 0; i < len; i++)
    {
        b[i] = a[i];
    }
    sort(b,b + len);

    int **LCS = new int*[len+1];
    for(int i = 0; i < len + 1; i++)
    {
        LCS[i] = new int[len+1];
    }

    for(int i = 0; i < len + 1; i++)
    {
        for(int j = 0; j < len + 1; j++)
        {
            if(i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
        }
    }

    for(int i = 1 ; i < len + 1; i++)
    {
        for(int j = 1; j < len + 1; j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                LCS[i][j] = max(max(LCS[i-1][j], LCS[i][j-1]), LCS[i-1][j-1] + 1);
            }
            else
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    for(int i = 0; i < len + 1; i++)
    {
        for(int j = 0; j < len + 1; j++)
            cout<<LCS[i][j]<<" ";
        cout<<endl;
    }

    return LCS[len][len];
}

int dp_h(int *a, int len)
{
    int *d = new int[len];
    int k = 1;
    d[0] = a[0];
    for(int i = 1; i < len; i++)
    {
        if(a[i] >= d[k - 1]) d[k++] = a[i];
        else
        {
            int j;
            for(j = k-1; j >= 0 && d[j] > a[j]; --j);
            d[j + 1] = a[i];
        }
    }
    return k;
}

int main()
{
    int a[] = {65, 70, 56, 75, 60, 68};
    int len = sizeof(a) / sizeof(a[0]);
    cout<<dp_1(a, len)<<endl;
    cout<<dp_2(a, len)<<endl;
    cout<<dp_h(a, len)<<endl;
    return 0;
}
