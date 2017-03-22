//Implement wild card pattern matching with support for '?' and '*'
//'?' matches any single character
//'*' matches any sequence of characters (including the empty sequence). 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool isMatch(string p, string s)
        {
            vector<vector<bool>> v(s.length() + 1);
            for(int i = 0; i < v.size(); ++i)
            {
                vector<bool> v_son(p.length() + 1);
                v[i] = v_son;
            } 

            cout<<"Enter for!"<<endl;
            for(int i = 0; i < v.size(); ++i)
            {
                for(int j = 0; j < v[i].size(); ++j)
                {
                    cout<<"i: "<<i<<" j: "<<j<<endl;
                    if(i == 0 && j == 0) v[i][j] = true;
                    else if(i == 0) v[i][j] = false;
                    else if(s[i-1] == '?')
                    {
                        if(j != 0 && v[i-1][j-1] == true)
                        {
                            v[i][j] = true;
                        }
                        else
                        {
                            v[i][j] = false;
                        }
                    }
                    else if(s[i-1] == '*')
                    {
                        if(j == 0)
                        {
                            if(v[i-1][j] == true) v[i][j] = true;
                            else v[i][j] = false;
                        }
                        else if(v[i-1][j] == true) v[i][j] = true;
                        else if(v[i][j-1] == true) v[i][j] = true;
                        else v[i][j] = false;

                    }
                    else
                    {
                        if(j != 0 && v[i-1][j-1] == true && s[i-1] == p[j-1]) v[i][j] = true;
                        else v[i][j] = false;
                    }
                }
            }

            for(int i = 0; i < v.size(); ++i)
            {
                for(int j = 0; j < v[i].size(); ++j)
                {
                    cout<<v[i][j]<<" ";
                }
                cout<<endl;
            }

            return v[v.size()-1][v[0].size()-1];

        }
};

int main()
{
    Solution so;

    string s = "abefcdgiescdfimde";
    string p = "ab*cd?i*de";
    bool res = so.isMatch(s, p);
    cout<<"Res: "<<res<<endl;

    return 0;
}