int fa[N];

void init(int n)
{
	for(int i = 0; i <= n; fa[i] = i++);
}

void unin(int u, int v)
{
	fa[find(v)] = find(u);
}

int find(int u)
{
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}
