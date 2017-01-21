//Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <map>

using namespace std;

//此方法使用了hash_table，遍历整个数组的每个元素item，若hash_table中无item，则存放item的位置，以该item位置为结尾的无重复元素子串的大小为前一个item的大小 + 1。
//若hash_table中已经有了该item，那么将hash_table[item]的大小和前一个item的大小做对比，如果以前一个item位置为结尾的无重复元素子串包含了hash_table[item]，
//那么此item对应的无重复元素子串大小就是hash_table[item]到上一个item的距离，并且要更新hash_table[item]
//如果不包含，则以该item位置为结尾的无重复元素子串的大小等于前一个item的大小 + 1，并更新hash_table[item]
//这个方法的time complexity为O(n)，这个问题中包含了贪心算法，即我只关心上一个hash_table[item]，不关心上上一个hash_table[item]，因为和此时的item无关。
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

//此方法是O(n^2)，遍历到某个元素时，从此元素向前，逐个读取元素，放入hash_table中，直到到头或者hash_table中已经存放该元素了，此时return 该元素遍历的长度。
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