//无向图G有N个结点，它的边上带有正的权重值
//从结点开始走，并且一开始的时候身上有M元钱
//如果经过结点i，需要花掉s[i]元，如果没有足够的钱，就不能从结点经过
//在这样的限制条件下，找到从结点1到结点N的最短路径，或者输出该路径不存在
//如果存在多条最短路径，那么输出花钱最少的那条。
#include <iostream>
#include <vector>
using namespace std;

int find_min(int dis[4][4], vector<int> a)
{
    int min = -1;
    int min_index = -1;
    for(int i = 0; i < a.size(); i++)
    {
        
        vector<int>::iterator result = find()
    }
}

void DP_1(int dis[4][4], int price[4], int M, int start, int end)
{
    vector<int> a;
    a.append(start);
    int next = find_min(dis[4][4], a);
    while(next != end)
    {
        a.append(next);
        next = find_min(dis[4][4], a);
    }
    for(int i = 0; i < a.size(); i++)
    {
        cout<<i<<" ";
    }
}


int main()
{
    int dis[4][4] = {{0, 2, 3, 2}, {2, 0, 1, 1}, {3, 1, 0, 1}, {2, 1, 1, 0}};
    int price[4] = {1, 2, 3, 2};
    int M = 10;
    DP_1(dis, price, M, 0, 3);
    return 0;
}