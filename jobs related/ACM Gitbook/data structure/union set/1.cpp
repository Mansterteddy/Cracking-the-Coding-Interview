int fa[N];

void init(int n)
{
	for(int i = 0; i <= n; i++)
	{
		fa[i] = i;
	}
}

void unin(int u, int v)
{
	int fau = find(u);
	int fav = find(v);
	if(fau == fav) return;
	fa[fav] = fau;
}

int find(int u)
{
	if(fa[u] != u)
	{
		fa[u] = find(fa[u]);
	}

	return fa[u];
}
