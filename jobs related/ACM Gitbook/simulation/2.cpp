#include <iostream>

#define MAXN 1000

using namespace std;

void draw(const int n, char map[][MAXN], const int r, const int c) //从最大的向里面构造
{
	int size = (1 << (n+2));
	//构造四个角落
	map[r][c] = map[r+size-1][c+size-1] = map[r][c+size-1] = map[r+size-1][c] = '+';

	//构造外边框
	for(int i = 1; i < size-1; ++i)
	{
		map[r][c+i] = map[r+size-1][c+i] = '-';
		map[r+i][c] = map[r+i][c+size-1] = '|';
	}

	if(n==0) return;

	for(int i = 2; i < size/2-1; ++i)
	{
		map[r+i][c+size/2-i] = '/';
		map[r+i][c+size/2+i-1] = '\\';
	}

	draw(n-1, map, r+size/2, c+size/4);//iteration
}

int main()
{
	int cas, n;
	cin>>cas;

	while(cas--)
	{
		static char map[MAXN][MAXN];
		cin>>n;
		memset(map, ' ', sizeof(map));
		draw(n, map, 0, 0);
		int size = (1 << (n+2));

		for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < size; ++j)
			{
				cout<<map[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}