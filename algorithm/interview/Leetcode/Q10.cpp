/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//Tag：regular expression, Dynamic Programming
/*
p[i][j] = p[i-1][j-1] if p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.')
p[i][j] = p[i][j-2] if p[j-1] == '*'
p[i][j] = p[i-1][j] &&  (s[i-1] == p[j-2] )
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s1;

    string s = "aa";
    string p = "a";
    bool res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "aa";
    p = "aa";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "aaa";
    p = "aa";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "aa";
    p = "a*";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "aa";
    p = ".*";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "ab";
    p = ".*";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;

    s = "aab";
    p = "c*a*b*";
    res = s1.isMatch(s, p);
    cout<<"res: "<<res<<endl;


    return 0;
}