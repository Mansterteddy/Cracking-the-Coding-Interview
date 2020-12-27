#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
        string getPermutation(int n, int k)
        {
            string res = "";
            if(n == 0) return res;
            vector<char> v;
            k = k - 1;

            for(int i = 1; i <=n; ++i) v.push_back('0' + i); 

            int mul = 1;
            for(int i = 2; i <= n; ++i) mul *= i;

            for(int i = n; i >= 1; --i)
            {
                mul = mul / i;
                res += v[k / mul];
                v.erase(v.begin() + k / mul);   
                k = k % mul;
            }

            return res;
        }
};

int main()
{
    Solution s;
    int n = 3;
    int k = 6;
    string res = s.getPermutation(n, k);
    cout<<"res: "<<res<<endl;

    return 0;
}