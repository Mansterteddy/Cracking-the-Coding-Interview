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

//O(nlogn)算法实现
//这个方法非常巧妙
/*
针对65 70 56 75 60 68
d数组变化过程为
65
65 70
56 70
56 70 75
56 60 75
56 60 68
第一次看难以理解
当出现比当前最高位更大的元素后，那么k增加1，k本身记录的就是最长递增序列长度
当比当前最高位小时，就在d数组中寻找合适的位置，新来的元素取代原数组中某一位置的元素（比它大），
使得整个数组依然递增。
这时被它取代的元素所在位置对应的index，就是以被它取代的元素作为递增序列末尾的最长递增序列长度，
同时也是该元素作为递增序列末尾的最长递增序列长度
由于这个元素A，一定比被它取代的元素B小，因此当再来一个元素C，若是比这个元素A大，比A后面的元素小，
那么以这个元素+元素C的长度就是以C为递增序列末尾的最长递增序列长度
不管元素B和C的关系（要么小于，要么等于）
若是比这个元素小，那么也不需要管B和C的关系（一定等于）
所以我删去了元素B，并不会影响最终的结果
对于整个问题来说 我们只要记录到最长递增序列的长度和最后一个元素（不断更新 越小越好），
就可以知道新来的元素是否能使递增序列更长
可以观察到d数组始终是一个递增序列，因此可以使用二分插入，这样就是O(nlogn)的时间复杂度
*/
int find_index(int *d, int val, int start, int end)
{
    //d是个递增序列，找出val在d中的位置
    if(start == end) return start;
    if(val <= d[(start + end) / 2]) 
    {
        find_index(d, val, start, (start + end) / 2);
    }
    else
    {
        find_index(d, val, (start + end) / 2 + 1, end);
    }


}

int dp_h(int *a, int len)
{
    int *d = new int[len];
    int k = 1;
    d[0] = a[0];
    for(int i = 1; i < len; i++)
    {

        if(a[i] >= d[k - 1]) 
        {
            d[k] = a[i];
            k++;
        }
        else
        {
            int j = find_index(d, a[i], 0, k - 1);
            //int j;
            //for(j = k-1; j >= 0 && d[j] > a[i]; --j);
            d[j] = a[i];
        }
    }
    
    for(int i = 0; i < len; i++)
    {
        cout<<d[i]<<" ";
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
