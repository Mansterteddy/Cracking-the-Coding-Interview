/*
有n种技能，每种技能只能使用一次，怪物有m点血，问最少需要多少种技能可以把怪物杀死？
每种技能有两个数值a和b，a表示攻击力，b表示当怪物的血量小于等于b时，这种技能的攻击力可以变为2a。
*/

#include <stdio.h>
#include <string.h>

struct node
{
	int M, spell;
}a[11];

int hp, n;
int vis[11];
int ans;

void dfs(int k, int HP)
{
	int i;
	if(k >= ans) return;
	if(HP <= 0)
	{
		if(ans > k)
			ans = k;
		return;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			HP <= a[i].M ? dfs(k+1, HP-a[i].spell*2) : dfs(k+1, HP-a[i].spell);
			vis[i] = 0;
		}
	}

}

int main()
{
	int i;
	while(~scanf("%d%d", &n, &hp))
	{
		for(int i = 1; i <=n; ++i)
		{
			scanf("%d%d", &a[i].spell, &a[i].M);
		}
		ans = 12;
		memset(vis, 0, sizeof(vis));
		dfs(0, hp);
		if(ans != 12) printf("%d\n", ans);
		else printf("-1\n");
	}

	return 0;
}