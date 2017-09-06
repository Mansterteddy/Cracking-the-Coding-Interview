//假设已知有n个人和m对好友关系（存于数字r）。如果两个人是直接或者间接的好友，则认为他们是同一个朋友圈。求这n个人里一共有多少朋友圈。

#include <iostream>

using namespace std;

#define N 1000
int leader[N+1] = {0};

void setLeader()
{
    int i = 1;
    for(i = 1; i <= N; ++i)
    {
        leader[i] = i;
    }
}

int findLeader(int n)
{
    int r = n;
    while(leader[r] != r)
    {
        r = leader[r];
    }

    return r;
}

void uniteSet(int leaderX, int leaderY)
{
    leader[leaderX] = leaderY;
}

int input[] = {
    3, 4, 
    4, 2,
    7, 6,
    5, 1,
    3, 9,
    11, 8, 
    6, 10,
    9, 13,
    11, 12
};

int test[] = {
    3, 2,
    9, 4,
    7, 10,
    6, 7,
    13, 4,
    8, 12,
    6, 9,
    4, 7,
    11, 10,
    1, 2,
    12, 13,
    7, 13
};

int main()
{
    int numberOfSets = 13;

    setLeader();

    int i = 0;
    int j = 0;
    int n = sizeof(input) / sizeof(input[0]) / 2;

    for(int j = 0; j < n; ++j)
    {
        int u = input[i++];
        int v = input[i++];

        u = findLeader(u);
        v = findLeader(v);

        if(u != v)
        {
            uniteSet(u, v);
            numberOfSets--;
        }
    }

    i = 0;
    n = sizeof(test) / sizeof(test[0]) / 2;

    for(int j = 0; j < n; ++j)
    {
        int u = test[++i];
        int v = test[++i];

        u = findLeader(u);
        v = findLeader(v);

        if(u != v)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }

    cout<<numberOfSets<<endl;

    return 0;
}