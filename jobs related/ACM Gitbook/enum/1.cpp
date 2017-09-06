/*
题意：输入一个正整数n，按从小到大的顺序输出形如a/b=n的表达式，其中100<=a<=999，2<=n<=79，且b必须是素数。
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(int x)
{
	bool flag = true;

	for(int i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 100; i < 1000; ++i)
	{
		for(int j = 1; j < i; ++j)
		{
			if(check(j) && (i % j == 0) && (i / j == n))
			{
				cout<<i<<"/"<<j<<"="<<n<<endl;
			}
		}
	}

	return 0;
}