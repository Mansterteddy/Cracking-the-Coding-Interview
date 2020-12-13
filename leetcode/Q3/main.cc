#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s) {
            int final_max_len = 0;
            int max_len = 0;
            map<char, int> pos_map;

            for(int i = 0; i < s.length(); ++i){
                auto cur_item = pos_map.find(s[i]);

                if(cur_item == pos_map.end()){
                    max_len += 1;
                }
                else{
                    if((i - max_len) > pos_map[s[i]]){
                        max_len += 1;                        
                    }
                    else{
                        max_len = i - pos_map[s[i]];
                    }
                }
                pos_map[s[i]] = i;
                if(max_len > final_max_len)
                    final_max_len = max_len;
            }

            return final_max_len;
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