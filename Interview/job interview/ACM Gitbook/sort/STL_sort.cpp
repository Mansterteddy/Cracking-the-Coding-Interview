#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[5] = {2, 1, 0, 3, 4};

int cmp1(int a, int b)
{
	return a > b;
}

int cmp2(int a, int b)
{
	return a < b;
}

void _print()
{
	for(int i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

int main()
{
	sort(a, a+5);
	_print();

	sort(a, a+5, cmp1);
	_print();

	sort(a, a+5, cmp2);
	_print();

	return 0;
}