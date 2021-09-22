#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    
    string add(string num1, string num2){
        
        //cout << "enter add, num1: " << num1 << " num2: " << num2 << endl;

        if(num1 == "0") return num2;
        if(num2 == "0") return num1;
        
        int num1_len = num1.length();
        int num2_len = num2.length();
        if(num1_len > num2_len) swap(num1, num2);

        int next_val = 0;
        string res = "";

        for(int i = 0; i < num1.length(); ++i){
            int cur_val = (num1[num1.length()-1-i] - '0') + (num2[num2.length()-1-i] - '0') + next_val;

            if(cur_val >= 10){
                next_val = 1;
                cur_val %= 10;
            }
            else{
                next_val = 0;
            }
            char cur_char = '0' + cur_val;
            res = cur_char + res;
        }

        if(num1.length() < num2.length()){
            for(int i = num1.length(); i < num2.length(); ++i){
                int cur_val = (num2[num2.length()-1-i] - '0') + next_val;

                if(cur_val >= 10){
                    next_val = 1;
                    cur_val %= 10;
                }
                else{
                    next_val = 0;
                }
                char cur_char = '0' + cur_val;
                res = cur_char + res;
            }
        }

        if(next_val != 0){
            char cur_val = '0' + next_val;
            res = cur_val + res;
        }

        //cout << "num1: " << num1 << " num2: " << num2 << " res: " << res << endl;

        return res;
    }

    string multiply_int(int cur_i, string num){

        //cout << "enter multiply_int, cur_i: " << cur_i << " num: " << num << endl;
        string res = "";

        if(cur_i == 0) return res;
        if(cur_i == 1) return num;

        int next_val = 0;

        for(int i = num.length()-1; i >=0; --i){
            int cur_item = (num[i] - '0') * cur_i + next_val;
            if(cur_item >= 10){
                next_val = cur_item / 10;
                cur_item %= 10;
            }
            else{
                next_val = 0;
            }
            char cur_val = '0' + cur_item;
            res = cur_val + res;
        }

        if(next_val != 0){
            char cur_val = '0' + next_val;
            res = cur_val + res;
        }

        //cout << "cur_i: " << cur_i << " num: " << num << " res: " << res << endl;

        return res;
    }

    string multiply(string num1, string num2) {
        int num1_len = num1.length();
        int num2_len = num2.length();

        if(num1_len > num2_len) swap(num1, num2);

        if(num1 == "0" || num2 == "0") return "0";
        if(num1 == "1") return num2;
        if(num2 == "1") return num1;

        set<int> num2_set;
        for(int i = 0; i < num2.length(); ++i){
            num2_set.insert(num2[i] - '0');
        }

        map<int, string> val_dict;
        for(auto item: num2_set){
            //cout << "set item: " << item << endl;
            val_dict[item] = multiply_int(item, num1);
            //cout << "debug: " << val_dict[item] << endl;
        }

        string res = "0";
        int cur_zero = 0;
        for(int i = num2.length() - 1; i >=0; --i){
            string cur_val = val_dict[num2[i]-'0'];
            //cout << "key: " << num2[i] << " cur_value: " << cur_val << endl;
            for(int j = 0; j < cur_zero; ++j)
                cur_val += "0";
            res = add(res, cur_val);
            cur_zero += 1;
        }

        return res;
    }
};

int main(){

    Solution s = Solution();

    string res_1 = s.multiply("2", "3");
    cout << res_1 << endl;

    string res_2 = s.multiply("123", "456");
    cout << res_2 << endl;

    return 0;
}