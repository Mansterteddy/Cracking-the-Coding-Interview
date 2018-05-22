/*
样例输入
AB
BA
样例输出
BA
*/

#include <iostream>
#include <string>

using namespace std;

char a[27], b[27];

void solve(int as, int ae, int bs, int be)
{
	for(int i = bs; i < be; ++i)
	{
		if(a[as] == b[i])
		{
			solve(as+1, as+i-bs+1, bs, i);
			solve(as+i-bs+1, ae,i+1, be);
			break;
		}
	}
	if(as < ae) cout<<a[as];
}

int main()
{
	scanf("%s%s", a, b);
	solve(0, strlen(a), 0, strlen(b));
	
	return 0;
}