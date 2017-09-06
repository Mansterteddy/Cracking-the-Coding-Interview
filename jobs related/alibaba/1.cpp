#include <iostream>

using namespace std;

int goods[100][100];
int dp[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int dfs(int x, int y)
{
	int max = -1;
	if(dp[x][y] != -1) return dp[x][y];

	for(int i = 0; i < 4; ++i)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && goods[xx][yy] < goods[x][y])
		{
			int temp = dfs(xx, yy);
			if(temp > max)
				max = temp;
		}
	}

	dp[x][y] = max + 1;
	return dp[x][y];
}

int main()
{
	int res = 0;

	memset(dp, -1, sizeof(dp));

	cin>>n>>m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int good = 0;
			cin>>good;
			goods[i][j] = good;
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int temp_res = dfs(i, j);
			if(temp_res > res) res = temp_res;
		}
	}

	cout<<res+1<<endl;

	return 0;
}