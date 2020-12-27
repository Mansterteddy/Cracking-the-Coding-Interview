#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define eps 1e-8
#define pi acos(-1)

int n, k;
int arr[10010];

int ok(double x)
{
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += (int)arr[i]/x;

	return ans;
}

int main()
{
	int nCase;
	double l, r, mid;
	scanf("%d", &nCase);

	while(nCase--)
	{
		scanf("%d%d", &n, &k);
		l = r = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			arr[i] *= arr[i];
			r = max(r, (double)arr[i]);	
		}

		while(l + eps < r)
		{
			mid = (l + r) / 2.0;
			if(ok(mid) >= k+1) l = mid;
			else r = mid;
		}

		printf("%4lf\n", pi*l);
	}
	return 0;
}