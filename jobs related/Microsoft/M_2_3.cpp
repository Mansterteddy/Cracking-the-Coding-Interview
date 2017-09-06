
/*
描述
Little Hi has a box which consists of 2xN cells as illustrated below.
+----+----+----+----+----+----+
| A1 | A2 | A3 | A4 | .. | AN |
+----+----+----+----+----+----+
| B1 | B2 | B3 | B4 | .. | BN |
+----+----+----+----+----+----+



There are some coins in each cell. For the first row the amounts of coins are A1, A2, … AN and for the second row the amounts are B1, B2, … BN.
Each second Little Hi can pick one coin from a cell and put it into an adjacent cell. (Two cells are adjacent if they share a common side. For example, A1 and A2 are adjacent; A1 and B1 are adjacent; A1 and B2 are not adjacent.)
Now Little Hi wants that each cell has equal number of coins by moving the coins. He wants to know the minimum number of seconds he needs to accomplish it.
输入
The first line contains an integer, N. 2 <= N <= 100000
Then follows N lines. Each line contains 2 integers Ai and Bi. (0 <= Ai, Bi <= 2000000000)
It is guaranteed that the total amount of coins in the box is no more than 2000000000 and is a multiple of 2N.
输出
The minimum number of seconds.
样例输入
2
3 4
6 7


样例输出
4


*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N, ans = 0;
    long long avg = 0;
    cin >> N;
    
    vector<vector<long long> > tab(N, vector<long long>(2, 0));
    for(int i = 0; i < N; i++)
    {
        cin >> tab[i][0] >> tab[i][1];
        avg += tab[i][0] + tab[i][1];
    }
    
    avg /= 2 * N;
    
    for(int i = 0; i < N - 1; i++)
    {
        long long col = tab[i][0] + tab[i][1];
        ans += abs(col - 2 * avg);
        
        if(col > 2 * avg)
        {
            if(tab[i][0] >= avg && tab[i][1] >= avg)
            {
                tab[i + 1][0] += tab[i][0] - avg;
                tab[i + 1][1] += tab[i][1] - avg;
            }
            else
            {
                int j = tab[i][0] >= avg ? 0 : 1;
                ans += avg - tab[i][1 - j];
                tab[i + 1][j] += col - 2 * avg;
            }
        }
        else if(col <= 2 * avg)
        {
            if(tab[i][0] <= avg && tab[i][1] <= avg)
            {
                tab[i + 1][0] += tab[i][0] - avg;
                tab[i + 1][1] += tab[i][1] - avg;
            }
            else
            {
                int j = tab[i][0] <= avg ? 0 : 1;
                ans += tab[i][1 - j] - avg;
                tab[i + 1][j] += col - 2 * avg;
            }
        }
    }
    
    ans += abs(tab[N - 1][0] - avg);
    cout << ans;
    
    return 0;
}
