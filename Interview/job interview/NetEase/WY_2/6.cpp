/*
WY_6
小易将n个棋子摆放在一张无限大的棋盘上。第i个棋子放在第x[i]行y[i]列。同一个格子允许放置多个棋子。每一次操作小易可以把一个棋子拿起并将其移动到原格子的上、下、左、右的任意一个格子中。小易想知道要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数.

输入描述:
输入包括三行,第一行一个整数n(1 ≤ n ≤ 50),表示棋子的个数
第二行为n个棋子的横坐标x[i](1 ≤ x[i] ≤ 10^9)
第三行为n个棋子的纵坐标y[i](1 ≤ y[i] ≤ 10^9)


输出描述:
输出n个整数,第i个表示棋盘上有一个格子至少有i个棋子所需要的操作数,以空格分割。行末无空格

如样例所示:
对于1个棋子: 不需要操作
对于2个棋子: 将前两个棋子放在(1, 1)中
对于3个棋子: 将前三个棋子放在(2, 1)中
对于4个棋子: 将所有棋子都放在(3, 1)中

输入例子1:
4
1 2 4 9
1 1 1 1

输出例子1:
0 1 3 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int cal_dis(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

vector<vector<int>> get_dis_vec(vector<pair<int, int>> axis)
{
	vector<vector<int>> res;

	vector<pair<int, int>> new_axis;

	map<pair<int, int>, int> new_map;

	for(int i = 0; i < axis.size(); ++i)
	{
		for(int j = 0; j < axis.size(); ++j)
		{
			pair<int, int> temp;
			temp.first = axis[i].first;
			temp.second = axis[j].second;

			if(new_map.find(temp) == new_map.end())
			{
				new_axis.push_back(temp);
				new_map[temp] = 1;
			}

		}
	}

	for(int i = 0; i < new_axis.size(); ++i)
	{
		vector<int> res_son;
		for(int j = 0; j < axis.size(); ++j)
		{
			pair<int, int> temp_1 = new_axis[i];
			pair<int, int> temp_2 = axis[j];
			int distance = cal_dis(temp_1, temp_2);
			res_son.push_back(distance);
		}
		sort(res_son.begin(), res_son.end());
		res.push_back(res_son);
	}

	return res;
}

vector<int> get_res(vector<pair<int, int>> axis)
{
	vector<int> res;

	vector<vector<int>> dis_vec = get_dis_vec(axis);

	for(int i = 0; i < dis_vec.size(); ++i)
	{
		for(int j = 0; j < dis_vec[i].size(); ++j)
		{
			if(j == 0) dis_vec[i][j] = dis_vec[i][j];
			else dis_vec[i][j] += dis_vec[i][j-1];
		}
	}


	/*for(int i = 0; i < dis_vec.size(); ++i)
	{
		for(int j = 0; j < dis_vec[i].size(); ++j)
		{
			cout<<dis_vec[i][j]<<" ";
		}
		cout<<endl;
	}*/

	for(int i = 0; i < axis.size(); ++i)
	{
		int min = -1;
		for(int j = 0; j < dis_vec.size(); ++j)
		{
			if(j==0) min = dis_vec[j][i];
			else min = min > dis_vec[j][i] ? dis_vec[j][i] : min;
		}
		res.push_back(min);
	}


	return res;
}

int main()
{
	int n = 0;
	cin>>n;

	vector<int> x_vec;
	for(int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin>>temp;
		x_vec.push_back(temp);
	}

	vector<int> y_vec;
	for(int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin>>temp;
		y_vec.push_back(temp);
	}

	vector<pair<int, int>> axis;
	for(int i = 0; i < n; ++i)
	{
		pair<int, int> temp;
		temp.first = x_vec[i];
		temp.second = y_vec[i];
		axis.push_back(temp);
	}

	vector<int> res = get_res(axis);

	for(int i = 0; i < res.size()-1; ++i)
	{
		cout<<res[i]<<" ";
	}

	cout<<*(res.end()-1);

	return 0;
}