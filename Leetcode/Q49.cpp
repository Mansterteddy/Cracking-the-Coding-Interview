//Given an array of strings, group anagrams togther
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            vector<vector<string>> res;

            map<string, vector<string>> m1;
            vector<string> sv1;

            for(int i = 0; i < strs.size(); ++i)
            {
                string ret = return_val(strs[i]);
                if(!m1.count(ret))
                {
                    sv1.push_back(ret);
                    vector<string> v_son = {strs[i]};
                    m1[ret] = v_son;
                }
                else
                {
                    m1[ret].push_back(strs[i]);
                }
            }

            for(int i = 0; i < sv1.size(); ++i)
            {
                string s = sv1[i];
                res.push_back(m1[s]);
            }

            return res;

        }

        string return_val(string s)
        {
            vector<int> v1;
            string res;

            for(int i = 0; i < s.length(); ++i)
            {
                v1.push_back(s[i]);
            }
            sort(v1.begin(), v1.end());
            for(int i = 0; i < v1.size(); ++i)
            {
                res += v1[i];
            }
            return res;
        }
};

int main()
{
    Solution s;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}