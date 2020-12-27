/*
完全背包问题

100 4
71 5
21 3
20 4
8 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

	vector<int> update_volume_vec;
	vector<int> update_value_vec;
	for(int i = 0; i < num; ++i)
	{
		int max_contain = int(floor(float(contain) / float(volume_vec[i])));
		int j = 0;
		for(; (1 << j) <= max_contain; ++j)
		{
			int temp_size = 1 << j;
			update_volume_vec.push_back(volume_vec[i] * temp_size);
			update_value_vec.push_back(value_vec[i] * temp_size);
		}
		int residual = max_contain - (1 << (j - 1));
		if(residual != 0)
		{
			update_volume_vec.push_back(volume_vec[i] * residual);
			update_value_vec.push_back(value_vec[i] * residual);
		}
	}

	for(int i = 0; i < update_volume_vec.size(); ++i)
	{
		cout<<update_volume_vec[i]<<" "<<update_value_vec[i]<<endl;
	}


	num = update_value_vec.size();
	volume_vec = update_volume_vec;
	value_vec = update_value_vec;

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
	}

	return 0;
}