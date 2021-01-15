//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses

//Tag: Recursion

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        vector<string> generateParenthesis(int n)
        {
            generateP(n, 0, "");
            return res;
        }

    private:
        vector<string> res;
        void generateP(int n, int m, string str)
        {
            if(n == 0 && m == 0)
            {
                res.push_back(str);
            }
            else if(n == 0 && m != 0)
            {
                str += ")";
                generateP(n, m - 1, str);
                str.pop_back();
            }
            else if(n != 0)
            {
                if(m == 0)
                {
                    str += "(";
                    generateP(n - 1, m + 1, str);
                    str.pop_back();
                }
                else
                {
                    str += "(";
                    generateP(n - 1, m + 1, str);
                    str.pop_back();

                    str += ")";
                    generateP(n, m - 1, str);
                    str.pop_back();
                }
            }
            
        }
};

int main()
{
    Solution s;

    vector<string> res = s.generateParenthesis(4);

    for(int i = 0; i < res.size(); ++i)
    {
        cout<<"Res: "<<res[i]<<endl;
    }

    return 0;
}