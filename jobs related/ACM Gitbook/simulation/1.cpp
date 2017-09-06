//POJ 1068

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int p[21] = {0};
	int w[20];
	int str[40];
	int n;

	int cases;
	cin>>cases;

	while(cases--)
	{
		memset(str, 0, sizeof(str));
		cin>>n;
		int i, j, k;

		for(i=1; i<=n; ++i)
		{
			cin>>p[i];
		}

		for(j=0, i=1; i<=n; ++i)
		{
			for(k=0;;++k)
			{
				if(k < p[i] - p[i-1]) ++j;
				else if(k == p[i] - p[i-1])
				{
					str[j++] = 1;
					break;
				}
			}
		}

		const int length = j;
		int count;
		for(i=0; i < length; ++i)
		{
			if(str[i]==1)
			{
				count=2;
				for(j=i-1;;j--)
				{
					if(str[j]==0)
					{
						str[i]=str[j]='F';
						break;
					}
					else count++;
				}
				cout<<count/2<<' ';
			}
		}
		cout<<endl;

	}

	return 0;
}