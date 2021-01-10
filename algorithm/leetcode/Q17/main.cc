#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:

        vector<string> generate(map<string, vector<string>>& key_map, string& digits, int index){

            if(index == digits.length() - 1){
                return key_map[digits.substr(index)];
            }
            else{
                vector<string> last_res = generate(key_map, digits, index + 1);
                vector<string> cur_val = key_map[digits.substr(index, 1)];
                vector<string> res;
                for(int i = 0; i < cur_val.size(); ++i){
                    for(int j = 0; j < last_res.size(); ++j){
                        string new_str = cur_val[i] + last_res[j];
                        res.push_back(new_str);
                    }
                }
                return res;
            }
        }

        vector<string> letterCombinations(string digits){

            if(digits.length() == 0){
                vector<string> res = vector<string>();
                return res;
            }

            map<string, vector<string>> key_map;
            key_map["2"] = {"a", "b", "c"};
            key_map["3"] = {"d", "e", "f"};
            key_map["4"] = {"g", "h", "i"};
            key_map["5"] = {"j", "k", "l"};
            key_map["6"] = {"m", "n", "o"};
            key_map["7"] = {"p", "q", "r", "s"};
            key_map["8"] = {"t", "u", "v"};
            key_map["9"] = {"w", "x", "y", "z"};

            vector<string> res = generate(key_map, digits, 0);
            return res;
        }

};


int main(){

    Solution s = Solution();

    string str = "23";
    vector<string> res = s.letterCombinations(str);

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }

    return 0;
}