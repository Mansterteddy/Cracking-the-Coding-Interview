#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

#define maxn 1000+10

using namespace std;

int final;
int vis[maxn][maxn];
int map[maxn][maxn];
int s[maxn][maxn];
int m, n;

int move_arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct point
{
	int x, y;
};

bool check(point a)
{
	if(a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= m && vis[a.x][a.y] == 0 && map[a.x][a.y] <= final)
		return true;
	return false;
}

int bfs(int x, int y)
{
	queue<point> que;
	point now, temp;
	int count = 1;
	now.x = x;
	now.y = y;
	que.push(now);
	vis[x][y] = 1;
	s[x][y] = 1;

	while(!que.empty())
	{
		temp = que.front();
		que.pop();
		if(s[temp.x][temp.y] == 1)
		{
			for(int i = 0; i < 4; i++)
			{
				now.x = temp.x + move_arr[i][0];
				now.y = temp.y + move_arr[i][1];
				if(check(now))
				{
					que.push(now);
					vis[now.x][now.y] = 1;
					count++;
					s[now.x][now.y] = 1;
				}
			}
		}
	}

	return count;
}

int main()
{
	int p1, p2;
	while(scanf("%d%d%d%d", &n, &m, &p1, &p2) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		memset(s, 0, sizeof(s));

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		final = map[p1][p2];
		printf("%d\n", bfs(p1, p2));
	}

	return 0;
}