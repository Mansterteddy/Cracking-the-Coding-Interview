//Tag: Array
//这道题就是先找第一个和第二个字符串的共同之处，然后接着用此共同之处，去找和第三个字符串的共同之处。
//做这种题的时候，要记着判断算法的下界，可以很明确地知道，至少必须遍历所有的string才可以找到解，所以就坚信自己的方法是正确的。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        string longestCommonPrefix(vector<string>& strs)
        {
            if(strs.size() == 0) return "";
            string s1 = strs[0];
            for(int i = 1; i < strs.size(); ++i)
            {
                string s2;
                for(int j = 0; j < strs[i].size(); ++j)
                {
                    if(s1[j] == strs[i][j])
                    {
                        s2.push_back(s1[j]);
                    }
                    else break;
                }
                s1 = s2;
            }

            return s1;
        }
};

int main()
{
    vector<string> strs;
    /*strs.push_back("aba");
    strs.push_back("abdb");
    strs.push_back("abddz");
    strs.push_back("");*/

    Solution s;
    string res = s.longestCommonPrefix(strs);
    cout<<"res: "<<res<<endl;

    return 0;
}