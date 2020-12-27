#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 200001;
int queue[MAX], vis[MAX];

bool check(int x)
{
	if(x >= 0 && x < MAX && vis[x] == -1) return 1;
	else return 0;
}

int BFS(int start, int end)
{
	memset(vis, -1, sizeof(vis));

	int front = 0, back = 0, now;
	queue[back++] = start;
	vis[start] = 0;

	while(front <= back)
	{
		now = queue[front++];
		if(now == end) return vis[end];
		if(check(now-1))
		{
			queue[back++] = now - 1;
			vis[now-1] = vis[now] + 1;
		}
		if(check(now+1))
		{
			queue[back++] = now + 1;
			vis[now+1] = vis[now] + 1;
		}
		if(check(now * 2))
		{
			queue[back++] = now*2;
			vis[now*2] = vis[now] + 1;
		}
	}
}

int main()
{
	int start, end;
	while(scanf("%d%d", &start, &end) != EOF)
		printf("%d\n", BFS(start, end));

	return 0;
}