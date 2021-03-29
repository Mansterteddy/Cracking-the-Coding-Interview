#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string removeKdigits(string num, int k){

            if(k == 0) return num;
            if(k >= num.size()) return "0";
            
            int keep_len = num.size() - k;

            vector<char> res_vec;

            res_vec.push_back(num[0]);

            int cur_index = 1;
            int left_len = num.size() - 1;

            while(cur_index < num.size()){
                
                // cout << "Debug: ";
                // for(auto ch: res_vec){
                //     cout << ch << " ";
                // }
                // cout << endl;

                if(res_vec.size() < keep_len && (left_len == (keep_len - res_vec.size()))){
                    res_vec.push_back(num[cur_index]);
                    left_len -= 1;
                    cur_index += 1;
                    continue;
                }

                bool is_larger_flag = false;

                for(int i = res_vec.size() - 1; i >= 0; --i){
                    if(res_vec[i] <= num[cur_index]){
                        break;
                    }
                    else{
                        if(left_len > keep_len - res_vec.size()){
                            is_larger_flag = true;
                            res_vec.pop_back();
                        }
                    }
                }

                if(is_larger_flag || res_vec.size() < keep_len){
                    res_vec.push_back(num[cur_index]);
                }
                cur_index += 1;
                left_len -= 1;

            }

            string final_res;
            bool start_with_zero = true;
            for(auto ch: res_vec){
                if(start_with_zero){
                    if(ch != '0'){
                        start_with_zero = false;
                        final_res += ch;
                    }
                }
                else{
                    final_res += ch;
                }
            }

            if(final_res == "") return "0";

            return final_res;
            
        }
};

int main(){

    Solution s = Solution();

    string num = "1432219";
    int k = 3;
    string res = s.removeKdigits(num, k);
    cout << res << endl;

    num = "10200";
    k = 1;
    res = s.removeKdigits(num, k);
    cout << res << endl;

    num = "10";
    k = 2;
    res = s.removeKdigits(num, k);
    cout << res << endl;

    num = "112";
    k = 1;
    res = s.removeKdigits(num, k);
    cout << res << endl;

    num = "1234567890";
    k = 9;
    res = s.removeKdigits(num, k);
    cout << res << endl;

    return 0;
}