#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

    int findLocalMax(vector<int> v)
    {
        return iterative_find(v, 0, v.size()-1);
    }

    int iterative_find(vector<int>& v, int start, int end)
    {
        if(start == end) return v[start];

        if(end - start == 1)
        {
            if(v[start] > v[end]) return v[start];
            else return v[end];
        }

        int mid = (start + end) / 2;
        if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return v[mid];
        else if(v[start] > v[mid])
        {
            return iterative_find(v, start, mid-1);
        }
        else
        {
            return iterative_find(v, mid+1, end);
        }
    }
};

int main()
{
    vector<int> st = {1, 2, 3, 4, 5, 0};

    Solution s;
    int res = s.findLocalMax(st);
    cout<<"res: "<<res<<endl;

    return 0;
}