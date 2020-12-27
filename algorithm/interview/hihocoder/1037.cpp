/*
样例输入
5
2
6 4
1 2 8
4 0 9 6
6 5 5 3 6
样例输出
28
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<vector<int>> maze;

	for(int i = 0; i < n; ++i)
	{
		vector<int> maze_son;
		for(int j = 0; j <= i; ++j)
		{
			int temp = 0;
			cin>>temp;
			maze_son.push_back(temp);
		}
		maze.push_back(maze_son);
	}

	vector<vector<int>> res;

	for(int i = 0; i < n; ++i)
	{
		vector<int> res_son;

		for(int j = 0; j <= i; ++j)
		{
			if(i == 0) res_son.push_back(maze[i][j]);
			else
			{
				if(j == 0)
				{
					res_son.push_back(res[i-1][0] + maze[i][j]);
				}
				else if(j == i)
				{
					res_son.push_back(res[i-1][i-1] + maze[i][j]);
				}
				else
				{
					int max_value = max(res[i-1][j-1], res[i-1][j]) + maze[i][j];
					res_son.push_back(max_value);
				}
			}
		}
		res.push_back(res_son);
	}

	int max_res = res[n-1][0];
	for(int i = 1; i < n; ++i)
	{
		if(max_res < res[n-1][i]) max_res = res[n-1][i];
	}

	cout<<max_res;

	return 0;
}