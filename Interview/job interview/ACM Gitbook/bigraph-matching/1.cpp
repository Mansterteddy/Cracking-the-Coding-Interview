/*
匈牙利算法解决二分图最大匹配问题
采用的邻接矩阵的形式，g[i][j]
maxn代表一边最多的顶点数，un代表左边顶点数，vn代表右边顶点数
linked[i]代表右边的第i个点与左边哪个点相匹配
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
const int maxn = 10;

int un, vn;//左边顶点数，右边顶点数
int g[maxn][maxn];//邻接矩阵来存储边
int linked[maxn];//右边的点和左边的哪个点匹配
bool vis[maxn];

bool dfs(int u)
{
    for(int v = 1; v <= vn; v++)
    {
        if(g[u][v] && !vis[v])
        {
            vis[v] = 1;
            //右边顶点还没有被匹配，或者已经匹配的前面左边顶点可以去寻找另一个匹配，
            //而把该右边顶点“腾出空位”让给当前左边顶点u
            if(!linked[v] || dfs(linked[v]))
            {
                linked[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    memset(linked, 0, sizeof(linked));
    for(int u = 1; u <= un; u++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(u))//去找u能不能匹配，如果可以匹配的话，ans++
            ans++;
    }
    return ans;
}

//m为题目中要求输入的左边顶点数，n为题目中要求输入的右边顶点数，k为边的数目
int k, m, n;

//注意！！！该模板是1到n，不是0到n-1！
int main()
{
    m = 4;
    n = 5;
    un = m;
    vn = n;

    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            g[i][j] = 1;
        }
    }

    cout<<"Ans is: "<<hungary()<<endl;

    for(int i = 0; i < maxn; ++i)
    {
        cout<<linked[i]<<" ";
    }
    cout<<endl;

    return 0;

}
