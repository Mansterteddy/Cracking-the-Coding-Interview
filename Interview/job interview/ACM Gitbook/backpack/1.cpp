/*
01背包问题
Test case:
100 4
71 5
23 1
22 2
10 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int contain = 0;
	int num = 0;
	cin>>contain;
	cin>>num;

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

	vector<vector<int>> res(num);

	for(int i = 0; i < num; ++i)
	{
		vector<int> temp(contain+1, 0);
		res[i] = temp;
	}

	for(int i = 0; i < num; ++i)
	{
		if(i == 0)
		{
			for(int j = volume_vec[i]; j < contain + 1; ++j)
			{
				res[i][j] = value_vec[i];
			}
		}
		else
		{
			for(int j = 0; j < contain + 1; ++j)
			{
				if(j - volume_vec[i] >= 0)	res[i][j] = max(res[i-1][j], res[i-1][j-volume_vec[i]] + value_vec[i]);
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