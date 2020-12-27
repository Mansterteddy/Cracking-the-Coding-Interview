#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct A
{
	int a, b;
}aa[5];

void init()
{
	aa[0].a = 3;
	aa[0].b = 2;
	aa[1].a = 2;
	aa[1].b = 4;
	aa[2].a = 2;
	aa[2].b = 5;
	aa[3].a = 2;
	aa[3].b = 3;
	aa[4].a = 1;
	aa[4].b = 9;
}

int cmp1(A aa, A bb)
{
	if(aa.a == bb.a)
	{
		return aa.b > bb.b;
	}
	return aa.a > bb.a;
}

int cmp2(A aa, A bb)
{
	if(aa.a == bb.a)
		return aa.b < bb.b;
	return aa.a > bb.a;
}

void _print()
{
	for(int i = 0; i < 5; i++)
	{
		printf("%d %d\n", aa[i].a, aa[i].b);
	}
}

int main()
{
	init();

	sort(aa, aa+5, cmp1);
	_print();

	sort(aa, aa+5, cmp2);
	_print();

	return 0;
}