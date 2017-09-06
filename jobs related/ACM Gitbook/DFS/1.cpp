#include <stdio.h>
#include <string.h>

bool used[1005][1005];
int a[1005][1005], n, m, p, q;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
	used[x][y] = 1;
	ans++;
	for(int k = 0; k < 4; k++)
	{
		int tx = x + dx[k], ty = y + dy[k];
		if(tx > 0 && ty > 0 && tx <= n && ty <= m && !used[tx][ty] && a[tx][ty] <= a[p][q])
		{
			dfs(tx, ty);
		}
	}
}

int main()
{
	while(scanf("%d%d%d%d", &n, &m, &p, &q) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		ans = 0;
		memset(used, 0, sizeof(used));
		dfs(p, q);
		printf("%d\n", ans);
	}
}