//rank的意义在于，记录物种之间的相关关系，保证关系处于平等、吃和被吃三类。

#include <stdio.h>

int fa[50005] = {0};
int rank[50005] = {0};
int n;

void initial()
{
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
		rank[i] = 0;
	}
}

int getfather(int x)
{
	if(x == fa[x]) return x;
	int oldfa = fa[x];
	fa[x] = getfather(fa[x]);
	rank[x] = (rank[x] + rank[oldfa]) % 3;
	return fa[x];
}

void unionset(int r, int x, int y)
{
	int fx, fy;
	fx = getfather(x);
	fy = getfather(y);
	
	if(fx == fy) return;
	
	fa[fx] = fy;
	rank[fx] = (rank[y] + r - rank[x] + 3) % 3;
	return;

}

int istrue(int d, int x, int y)
{
	int fx, fy, r;
	if(x > n || y > n || (x==y)&&(d==2))
		return 0;

	fx = getfather(x);
	fy = getfather(y);

	if(fx != fy) return 1;
	else
	{
		if(rank[x] == ((d-1) + rank[y])%3) return 1;
		else return 0;
	}

}

int main()
{
	int k, i, x, y, d;
	int ans = 0;
	scanf("%d%d", &n, &k);
	initial();

	for(i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		if(!istrue(d, x, y))
			ans++;
		else
			unionset(d-1, x, y);
	}
	printf("%d\n", ans);
	return 0;
}