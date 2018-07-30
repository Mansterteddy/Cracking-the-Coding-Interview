/*
有一个环，有n个点，请问从0点出发，经过k步回到原点有多少种方法？
动态规划问题，第i个点，经过k步回到原点的方法数量为d(i,k)，
递推公式为：d(i,k) = d(i-1,k-1) + d(i+1,k-1)
因为是环，因此公式可以改写为：d(i,k) = d((i-1+n)%n,k-1) + d((i+1+n)%n,k-1)
初始状态：d(0,0)=1, d(1,0)=0, ...
由于k是递增的，d(0,1)=d(n-1,0)+d(1,0)=0, d(1,1)=d(0,0)+d(2,0)=1
求取d(0,k)即可。
由于递归式只包含两列数据，因此在空间限制的情况下，可以只维持两个数组。
例子：
假设n=3 k=3
k\n 0   1   2
0   1   0   0
1   0   1   1
2   2   1   1
3   2   3   3
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Input n:" << endl;
    int n = 0;
    cin >> n;

    cout << "Input k:" << endl;
    int k = 0;
    cin >> k;

    //Special cases:
    if(n==1) 
    {
        cout << 1;
        return 1;
    }
    if(n==2)
    {
        if(k%2==0)
        {
            cout << 1;
            return 1;
        }
        else 
        {
            cout << 0;
            return 0;
        }
    }

    vector<int> first(n);
    vector<int> second(n);

    first[0] = 1;
    for(int i = 1; i < n; ++i)
    {
        first[i] = 0;
    }

    for(int j = 1; j <= k; ++j)
    {
        for(int h = 0; h < n; ++h)
        {
            second[h] = first[(h-1+n)%n] + first[(h+1+n)%n]; 
        }
        first = second;
    }

    cout<<second[0]<<endl;

    return second[0];
}