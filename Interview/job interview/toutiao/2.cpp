#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int> arr)
{

	vector<int> sum;
	for(int i = 0; i < arr.size(); ++i)
	{
		if(i == 0)
		{
			sum.push_back(arr[i]);
		}
		else
		{
			sum.push_back(sum.back() + arr[i]);
		}
	}

	vector<vector<int>> table;
	for(int i = 0; i < arr.size(); ++i)
	{
		vector<int> table_son;
		int min = 0;
		for(int j = 0; j <= i; ++j)
		{
			if(j == 0)
			{
				min = arr[i];
				table_son.push_back(arr[i]);
			}
			else
			{
				if(arr[i-j] < min)
				{
					table_son.push_back(arr[i-j]);
					min = arr[i-j];
				}
				else
				{
					table_son.push_back(min);
				}
			}
		}
		table.push_back(table_son);
	}

	int res = 0;

	for(int i = 0; i < table.size(); ++i)
	{
		int max = 0;

		for(int j = 0; j < table[i].size(); ++j)
		{
			if(j == 0)
			{
				max = table[i][j] * table[i][j];
				//cout<<"max 1: "<<max<<endl;
			}
			else if(j == table[i].size() - 1)
			{
				int ans = table[i][j] * sum[i];
				if(ans > max)
				{
					max = ans;
				}
				//cout<<"ans 1: "<<ans<<endl;
			}
			else
			{
				int ans = table[i][j] * (sum[i] - sum[i-j-1]);
				if(ans > max)
				{
					max = ans;
				}
				//cout<<"ans 2: "<<ans<<" sum[i]: "<<sum[i]<<" sum[i-j-1]: "<<sum[i-j-1]<<endl;
			}
		}

		if(i == 0) res = max;
		else
		{
			if(res < max) res = max;
		}

	}

	return res;
}

int main()
{
	int n = 0;
	cin>>n;

	vector<int> input;
	for(int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin>>temp;
		input.push_back(temp);
	}

	int res = get_max(input);
	cout<<res;

	return 0;
}