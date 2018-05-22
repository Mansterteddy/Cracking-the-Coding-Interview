#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	vector<int> vec;
	string line;

	getline(cin, line);
	istringstream iss(line);
	for(int i; iss >> i; vec.push_back(i)){}

	for(auto i : vec)
	{
		cout<<i<<" ";
	}

	return 0;
}