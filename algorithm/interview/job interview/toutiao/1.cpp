#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

vector<pair<int, int>> find_max(vector<pair<int, int>> points)
{
	sort(points.begin(), points.end(), cmp);

	map<int, int> m;

	for(int i = 0; i < points.size(); ++i)
	{
		if(m.find(points[i].first) == m.end())
		{
			m[points[i].first] = points[i].second;
		}
		else
		{
			if(points[i].second > m[points[i].first])
			{
				m[points[i].first] = points[i].second;
			}
		}
	}

	int prev = 0;
	for(auto i = m.rbegin(); i != m.rend(); i++)
	{
		if(i == m.rbegin())
		{
			prev = i->second;
		}
		else
		{
			if(prev > m[i->first])
			{
				m[i->first] = prev;
			}
			else
			{
				prev = m[i->first];
			}
		}
	}

	/*for(auto i = m.begin(); i != m.end(); ++i)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}*/

	vector<pair<int, int>> res;

	for(int i = 0; i < points.size(); ++i)
	{
		if(m[points[i].first] <= points[i].second)
		{
			res.push_back(points[i]);
		}
	}

	return res;

}

int main()
{
	int n = 0;
	cin>>n;

	vector<pair<int, int>> input;

	for(int i = 0; i < n; ++i)
	{
		pair<int, int> point;
		int x = 0;
		int y = 0;
		cin>>x>>y;
		point.first = x;
		point.second = y;
		input.push_back(point);
	}

	vector<pair<int, int>> res = find_max(input);

	for(int i = 0; i < res.size(); ++i)
	{
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}

	return 0;
}