#include <iostream>

using namespace std;

int n, m, k, t, f, p[30001], rank[30001], a, b;

int find(int x)
{
	if(x == p[x]) return x;
	else return p[x] = find(p[x]);
}

void un(int x, int y)
{
	a = find(x);
	b = find(y);

	if(a == b) return;
	if(rank[a] > rank[b]) p[b] = a;
	else
	{
		p[a] = b;
		if(rank[a] == rank[b])
			rank[b]++;
	}
}

int main()
{
	int i, sum;
	while(cin >> m >> n && (m || n))
	{
		for(i = 0; i < m; i++)
		{
			p[i] = i;
			rank[i] = 0;
		}

		for(i = 0; i < n; i++)
		{
			cin >> k;
			if(k >= 1)
			{
				cin >> f;
			}
			for(int j = 1; j < k; j++)
			{
				cin >> t;
				un(f, t);
			}
		}

		sum = 1;
		for(i = 1; i < m; i++)
		{
			if(find(i) == find(0))
				sum++;
		}

		cout<<sum<<endl;
	}

	return 0;
}