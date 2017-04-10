#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int climbStairs(int n)
        {
            if(n == 0) return 0;
            vector<int> v(n);
            v[0] = 1;
            v[1] = 2;
            for(int i = 2; i < n; ++i)
            {
                v[i] = v[i-2] + v[i-1];
            }

            return *(v.end() - 1);
        }
};

int main()
{
    Solution s;

    int res = s.climbStairs(4);
    cout<<"res: "<<res<<endl;

    return 0;
}