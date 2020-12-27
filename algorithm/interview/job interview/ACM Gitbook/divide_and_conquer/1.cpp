#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000000];

bool check(int x)
{
	bool vis[10], flag = true;
	memset(vis, false, sizeof(vis));

	while(x)
	{
		int tmp = x % 10;
		x /= 10;
		if(vis[tmp])
		{
			flag = false;
			break;
		}
		vis[tmp] = true;
	}

	return flag;
}

int n;
bool ok(int x)
{
	return arr[x] < n;
}

int main()
{
	int tot = 0;
	for(int i = 1; i <= 10000000; ++i)
	{
		if(check(i))
		{
			arr[tot++] = i;
		}
	}

	while(~scanf("%d", &n))
	{
		int r = tot-1, l = 0, mid, res;
		if(n <= 1)
		{
			cout<<"0"<<endl;
			continue;
		}

		while(l <= r)
		{
			mid = (l + r) / 2;
			if(arr[mid] < n)
			{
				l = mid + 1;
				res = mid;
			}
			else
			{
				r = mid - 1;
			}
		}

		cout<<arr[res+1]<<endl;

	}

	return 0;
}