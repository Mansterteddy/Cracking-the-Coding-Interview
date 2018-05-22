/*
描述
In a video game, Little Hi is going to assassinate the leader of an evil group, EL SUENO.

There are N high-value targets in the group, numbered from 1 to N. Each target has another target as his direct superior except for EL SUENO who has no superior. So the superior-subordinate hierarchy forms a tree-like structure. EL SUENO is at the root.

The cost of assassinating the i-th target is Ci. Before assassinating a target Little Hi has to obtain enough information about him. For the i-th target, Little Hi needs INi units of information. By assassinating a target Little Hi will obtain some information about the target's direct superior. More specifically, the i-th target has IPi units of information about his superior. So in order to assassinate EL SUENO, Little Hi needs to assassinate some of his direct subordinates so that the sum of information obtained is enough; assassinating the subordinates needs to assassinate their direct subordinates ... until it reaches some targets require zero information in advance. (Luckily if a target has no subordinate he always requires zero information.)

How Little Hi wants to know what is the minimum cost for successful assassinating EL SUENO.  

输入
The first line contains an integer N.

Then follow N lines. Each line describes a target with 4 integers, Fi, INi, IPi, Ci.  

Fi is i-th target's superior. For EL SUENO his Fi is zero.

INi is the amount of information needed to assassinate the i-th target. For a target has no subordinates his INi is always zero.

IPi is the amount of information the i-th target has about his superior Fi.

Ci is the cost of assassinating the i-th target.

For 30% of the data, 1 <= N <= 10, 0 <= INi, IPi <= 100

For 60% of the data, 1 <= N <= 100, 0 <= INi, IPi <= 1000

For 100% of the data, 1 <= N <= 2000, 0 <= Fi <= N, 0 <= INi, IPi <= 20000, 1 <= Ci <= 1000.

It is guaranteed that the N targets form a tree structure.

输出
The minimum cost. If Little Hi is not able to assassinate EL SUENO output a number -1.

样例输入
6
2 1 2 2
0 4 0 2
2 0 2 5
2 0 2 6
1 0 1 2
1 0 1 3
样例输出
11
*/

#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }

class node 
{
    public:
        node *p;
        vector<node*> childs;
        long long c, in, ip;
        node(vector<long long>& v) 
        {
            in = v[1];
            ip = v[2];
            c = v[3];
            p = nullptr;
        }
};

long long dfs(node* root) 
{
    vector<long long> tab(vector<long long>(root->in + 1, INF));
    tab[0] = 0;
    for (auto c: root->childs) 
    {
        long long costAll = dfs(c);
        for (long long j = root->in; j > 0 ; j --) 
        {
            tab[j] = min(tab[max(0, j-c->ip)] + costAll, tab[j]);
        }
    }
    return tab[root->in] + root->c;
}

int main(int argc, const char * argv[]) 
{
    long long N;
    cin >> N;
    
    vector<vector<long long>> v(N, vector<long long>(4, 0));
    
    for (long long i = 0; i < N; i ++) 
    {
        for (long long j = 0; j < 4; j ++) {
            cin >> v[i][j];
        }
    }

    // insert
    node* root = NULL;
    vector<node*> i2node(N, NULL);
    for (long long i = 0; i < N; i ++) 
    {
        node* cur = new node(v[i]);
        i2node[i] = cur;
        if (v[i][0] == 0) 
        {
            root = cur;
        }
        for (long long j = 0; j < i; j ++)
        {
            if (v[j][0] - 1 == i) 
            {
                cur->childs.push_back(i2node[j]);
                i2node[j]->p = cur;
            }
            if (v[i][0] - 1 == j)
            {
                cur->p = i2node[j];
                i2node[j]->childs.push_back(cur);
            }
        }
    }
    // dfs
    long long ans = dfs(root);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}

