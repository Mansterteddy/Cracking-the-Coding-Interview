#include <map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool wordPattern(string pattern, string s){
            bool res = false;
            map<char, string> pattern_map;
            unordered_set<string> str_set;

            s += " ";
            int cur_index = 0;
            int cur_count = 0;
            while(s != ""){
                int pos = s.find(" ");

                string cur_str = s.substr(cur_index, pos);
                //cout << cur_str << endl;

                char cur_key = pattern[cur_count];
                if(pattern_map.find(cur_key) != pattern_map.end()){
                    string cur_map_value = pattern_map[cur_key];
                    if(cur_map_value != cur_str){
                        return res;
                    }
                }
                else{
                    if(str_set.find(cur_str) != str_set.end()){
                        return res;
                    }
                    else{
                        pattern_map[cur_key] = cur_str;
                        str_set.insert(cur_str);
                    }

                }

                s = s.substr(pos + 1, s.size() - 1);
                cur_count += 1;
                //cout << s << endl;
            }

            if(cur_count != pattern.size()){
                return res;
            }
            
            return true;
        }
};

int main(){
    
    Solution s = Solution();

    string pattern_a = "abba";
    string str_a = "dog cat cat dog";
    bool res_a = s.wordPattern(pattern_a, str_a);
    cout << res_a << endl;

    string pattern_b = "abba";
    string str_b = "dog cat cat fish";
    bool res_b = s.wordPattern(pattern_b, str_b);
    cout << res_b << endl;

    string pattern_c = "aaaa";
    string str_c = "dog cat cat dog";
    bool res_c = s.wordPattern(pattern_c, str_c);
    cout << res_c << endl;

    string pattern_d = "abba";
    string str_d = "dog dog dog dog";
    bool res_d = s.wordPattern(pattern_d, str_d);
    cout << res_d << endl;

    string pattern_e = "jquery";
    string str_e = "jquery";
    bool res_e = s.wordPattern(pattern_e, str_e);
    cout << res_e << endl;

    return 0;
}