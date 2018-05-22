#include <iostream>

using namespace std;

int main()
{
	int n = 1000;

	int count = 0;

	for(int i = 1; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			cout<<i<<" "<<n/i<<endl;
			count += 2;
		}
	}

	cout<<"count: "<<count<<endl;

	return 0;
}