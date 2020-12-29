#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size() == 0) return "";

        string max_res = s.substr(0, 1);
        int max_len = 1;
        vector<int> first_vec{1};

        vector<vector<int>> info_vec;
        info_vec.push_back(first_vec);

        for(int i = 1; i < s.size(); ++i){
            vector<int> cur_info_vec{1};
            if(s[i] == s[i-1]){
                cur_info_vec.push_back(2);
                if(max_len < 2){
                    max_res = s.substr(i-1, 2);
                    max_len = 2;
                }

            }

            for(int j = 0; j < info_vec[info_vec.size()-1].size(); ++j){
                int temp_len = info_vec[info_vec.size()-1][j];
                if(i - 1 - temp_len >= 0){
                    if(s[i-1-temp_len] == s[i]){
                        cur_info_vec.push_back(temp_len + 2);
                        if(temp_len + 2 > max_len){
                            max_res = s.substr(i-1-temp_len, temp_len + 2);
                            max_len = temp_len + 2;
                        }
                    }
                }
            }
            info_vec.push_back(cur_info_vec);
        }

        return max_res;

    }
};


int main(){

    Solution s = Solution();

    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << res << endl;

    str = "cbbd";
    res = s.longestPalindrome(str);
    cout << res << endl;

    return 0;
}