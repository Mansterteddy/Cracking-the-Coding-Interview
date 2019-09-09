#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            int len = s.size();

            if (len == 0) return 0;
            if (len == 1) return 1;

            map<char, int> map_res;
            int cur_res = 0;
            int max_res = 1;
            for(int i = 0; i < len; ++i){
                
                if (map_res.find(s[i]) == map_res.end()){
                    cur_res += 1;
                }
                else{
                    if ((i - cur_res) > map_res[s[i]]){
                        cur_res += 1;
                    }
                    else{
                        cur_res = i - map_res[s[i]];

                    }
                }
                
                map_res[s[i]] = i;
                max_res = max(max_res, cur_res);

            }

            return max_res;
        }
};

int main(){

    cout << "LeetCode 003" << endl;

    Solution so = Solution();

    //string a = "abcabcbb";
    //string a = "bbbbb";
    //string a = "pwwkew";
    string a = "abcdda";

    int res = so.lengthOfLongestSubstring(a);

    cout << "Res: " << res << endl;

    return 0;
}