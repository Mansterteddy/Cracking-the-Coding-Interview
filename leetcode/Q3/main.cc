#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            int len = s.size();

            if(len <= 1) return len;

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

    Solution s = Solution();

    string str_a = "abcabcbb";
    int res_a = s.lengthOfLongestSubstring(str_a);
    cout << res_a << endl;

    string str_b = "bbbbb";
    int res_b = s.lengthOfLongestSubstring(str_b);
    cout << res_b << endl;

    string str_c = "pwwkew";
    int res_c = s.lengthOfLongestSubstring(str_c);
    cout << res_c << endl;

    string str_d = "abba";
    int res_d = s.lengthOfLongestSubstring(str_d);
    cout << res_d << endl;

    return 0;
}