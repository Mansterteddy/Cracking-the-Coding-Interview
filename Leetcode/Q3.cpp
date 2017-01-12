//Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int* res = new int[s.length()];
        memset(res, 0, s.length() * sizeof(int));
        res[0] = 1;
        //cout<<"res[0] "<<res[0]<<endl;

        map<char, int> mapping;
        mapping[s[0]] = 0;

        for(int i = 1; i < s.length(); ++i)
        {
            if(mapping.find(s[i]) == mapping.end())
            {
                res[i] = res[i-1] + 1;
                mapping[s[i]] = i;   
                cout<<s[i]<<" End! "<<res[i]<<endl;
            }
            else
            {
                if((i - 1) - res[i-1] + 1 <= mapping[s[i]])
                {
                    res[i] = (i - 1) - mapping[s[i]] + 1;
                    mapping[s[i]] = i;
                }
                else
                {
                    res[i] = res[i-1] + 1;
                    mapping[s[i]] = i;
                }

                cout<<s[i]<<" Not end! "<<res[i]<<endl;

            }
        }

        for(int i = 0; i < s.length(); ++i)
        {
            cout<<res[i]<<" ";
        }

        int max_res = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(max_res < res[i])
                max_res = res[i];
        }

        return max_res;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int* res = new int[s.length()];
        memset(res, 0, s.length() * sizeof(int));
        res[0] = 1;
        //cout<<"res[0] "<<res[0]<<endl;

        for(int i = 1; i < s.length(); i++)
        {
            map<char, int> mapping;
            //bool flag = false;
            res[i] = 1;
            mapping[s[i]] = 1;
            for(int j = 1; j <= i; j++)
            {
                if(mapping.find(s[i-j]) == mapping.end())
                {
                    mapping[s[i-j]] = 1;
                    res[i]++;
                    //cout<<"H: "<<s[i-j]<<" "<<res[i]<<endl;
                }
                else
                {
                    break;
                }

                /*
                if(s[i] != s[i-j])
                {
                    res[i]++;
                }
                else
                {
                    break;
                }*/
            }
        }
            /*
           //cout<<"s[i]"<<s[i]<<endl;
            for(int j = 0; j < res[i - 1]; j++)
            {
                //cout<<"s[]"<<i-1-j<<" "<<s[i-1-j]<<endl;
                if(s[i] == s[i-1-j])
                {
                    flag = true;
                    break;
                }
            }

            //cout<<"flag: "<<flag<<endl;
            if(flag)
            {
                //cout<<"1"<<endl;
                res[i] = 1;
            }
            else
            {
                //cout<<"2"<<i-1<<" "<<res[i-1]<<endl;
                res[i] = res[i - 1] + 1;
            }
            //cout<<"res: "<<res[i]<<endl;
            */

        for(int i = 0; i < s.length(); i++)
        {
            cout<<res[i]<<" ";
        }

        int max_res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(max_res < res[i])
                max_res = res[i];
        }

        return max_res;
    }
};

int main()
{
    Solution s1;
    //1 2 3 3 3 3 2 1
    string s = "abcabcbb";
    int res = s1.lengthOfLongestSubstring(s);
    cout<<"res: "<<res<<endl;

    //1 1 1 1 1
    s = "bbbbb";
    res = s1.lengthOfLongestSubstring(s);    
    cout<<"res: "<<res<<endl;

    //1 2 1 2 3 3
    s = "pwwkew";
    res = s1.lengthOfLongestSubstring(s);    
    cout<<"res: "<<res<<endl;

    //1 2 2 3
    s = "dvdf";
    res = s1.lengthOfLongestSubstring(s);    
    cout<<"res: "<<res<<endl;
    return 0;
}