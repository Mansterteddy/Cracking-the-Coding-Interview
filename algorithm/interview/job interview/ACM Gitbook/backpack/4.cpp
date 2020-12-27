/*
恰好装满背包的最优解

100 5
71 2
23 5
21 1
8 1
6 4

*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0xf0000000;

using namespace std;

int main()
{
	int contain = 0;
	int num = 0;
	cin>>contain>>num;

	vector<int> volume_vec;
	vector<int> value_vec;

	for(int i = 0; i < num; ++i)
	{
		int temp_volume = 0;
		int temp_value = 0;
		cin>>temp_volume>>temp_value;

		volume_vec.push_back(temp_volume);
		value_vec.push_back(temp_value);
	}

	vector<vector<int>> res;

	for(int i = 0; i < num; ++i)
	{
		vector<int> temp_vec(contain+1);
		for(int j = 0; j < contain + 1; ++j)
		{
			temp_vec[j] = INF;
		}
		res.push_back(temp_vec);
	}

	for(int i = 0; i < num; ++i)
	{
		if(i == 0)
		{
			res[i][0] = 0;
			res[i][volume_vec[i]] = value_vec[i];
		}
		else
		{
			for(int j = 0; j < contain + 1; ++j)
			{
				if(j >= volume_vec[i])	res[i][j] = max(res[i-1][j], res[i-1][j-volume_vec[i]] + value_vec[i]);
				else res[i][j] = res[i-1][j];
			}
		}

	}

	for(int i = 0; i < num; ++i)
	{
		for(int j = 0; j < contain + 1; ++j)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}