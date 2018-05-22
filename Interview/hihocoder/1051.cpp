/*
很显然，每次插入n个元素时，应该使得这n个元素，可以共同构成一个连续的段落，这就是贪心的性质。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(int i = 0; i < T; ++i)
	{
		int N, M;
		cin>>N>>M;
		vector<int> in;

		in.push_back(0);
		for(int i = 0; i < N; ++i)
		{
			int temp;
			cin>>temp;
			in.push_back(temp);
		}

		if(M >= N)
		{
			cout<<100<<endl;
			continue;
		}

		int ans = 0;

		for(int i = 1; i + M <= N; ++i)
		{
			ans = max(ans, in[i+M] - in[i-1] - 1);
		}

		cout<<ans<<endl;

	}

	return 0;
}
