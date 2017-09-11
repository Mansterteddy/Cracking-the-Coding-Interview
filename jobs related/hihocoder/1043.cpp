/*
样例输入
5 1000
144 990
487 436
210 673
567 58
1056 897
样例输出
5940
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> w, v;

	int n = 0;
	int m = 0;
	cin>>n>>m;
	
	for(int i = 0; i < n; ++i)
	{
		int temp_w, temp_v;
		cin>>temp_w>>temp_v;
		w.push_back(temp_w);
		v.push_back(temp_v);
	}

	vector<int> dp(m+1, 0);

	for(int i = 0; i < n; ++i)
	{
		for(int j = w[i]; j <= m; ++j)
		{
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
		}
	}

	cout<<dp[m];
	return 0;
}