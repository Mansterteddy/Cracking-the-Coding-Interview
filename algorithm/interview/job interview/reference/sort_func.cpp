#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y)
{
    return x < y;
}

bool cmp1(int x, int y)
{
    return x > y;
}

int main()
{
    vector<int> v = {1, 3, 5, 9, 8, 7, 4, 2};

    vector<int> v1(v);

    sort(v1.begin(), v1.end());
    for(int i = 0; i < v1.size(); ++i)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    vector<int> v2(v);
    sort(v2.begin(), v2.end(), cmp);
    for(int i = 0; i < v2.size(); ++i)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    vector<int> v3(v);
    sort(v3.begin(), v3.end(), cmp1);
    for(int i = 0; i < v3.size(); ++i)
    {
        cout<<v3[i]<<" ";
    }
    cout<<endl;

    return 0;
}