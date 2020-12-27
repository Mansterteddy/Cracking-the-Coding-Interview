/*
WY_4

小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。 
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。


输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。

输入例子1:
4
1 2 3 4

输出例子1:
4 2 1 3

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> get_res(vector<int> vec)
{
	vector<int> res(0);

	vector<int> forward;
	vector<int> backward;

	for(int i = vec.size() - 1; i >= 0; i -= 2)
	{
		forward.push_back(vec[i]);
	}

	for(int i = vec.size() - 2; i >= 0; i -= 2)
	{
		backward.push_back(vec[i]);
	}

	for(int i = 0; i < forward.size(); ++i)
	{
		res.push_back(forward[i]);
	}

	for(int i = backward.size()-1; i >= 0; --i)
	{
		res.push_back(backward[i]);
	}

	return res;
}

int main()
{
	int len = 0;
	cin>>len;

	vector<int> input;

	for(int i = 0; i < len; ++i)
	{
		int temp = 0;
		cin>>temp;
		input.push_back(temp);
	}

	vector<int> res = get_res(input);

	for(int i = 0; i < res.size()-1; ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<*(res.end()-1);

	return 0;
}