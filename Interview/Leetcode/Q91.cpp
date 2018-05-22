#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        int numDecodings(string s)
        {
            if(s.length() == 0) return 0;
            if(s[0] == '0') return 0;

            int len = s.length();
            vector<int> res(len);

            res[0] = 1;
            for(int i = 1; i < len; ++i)
            {
                if(s[i] == '0')
                {   
                    if(i != 1 && (s[i-1] == '1' || s[i-1] == '2')) res[i] = res[i-2];
                    else if(i == 1 && (s[i-1] == '1' || s[i-1] == '2')) res[i] = 1;
                    else return 0;
                }
                else 
                {
                    if(s[i-1] == '0')   res[i] = res[i-1];
                    else
                    {
                        int num = (s[i-1] - '0') * 10 + (s[i] - '0');
                        if(num < 27)
                        {
                            if(i == 1) res[i] = 2;
                            else res[i] = res[i-2] + res[i-1];
                        }
                        else
                        {
                            res[i] = res[i-1];
                        }
                    }
                }
            }

            return res[len-1];
        }
};

int main()
{
    Solution s;

    string str = "110";

    int res = s.numDecodings(str);
    cout<<"res: "<<res<<endl;

    return 0;
}