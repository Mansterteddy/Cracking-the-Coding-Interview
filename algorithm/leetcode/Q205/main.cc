#include <map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            map<char, char> keymap;
            unordered_set<char> value_set;

            for(int i = 0; i < s.length(); ++i){
                char s_i = s[i];
                char t_i = t[i];

                auto keymap_iter = keymap.find(s_i);
                if(keymap_iter == keymap.end()){
                    
                    auto value_set_iter = value_set.find(t_i);

                    if(value_set_iter == value_set.end()){
                        keymap[s_i] = t_i;
                        value_set.insert(t_i);
                    }
                    else{
                        return false;
                    }

                }
                else{
                    if(keymap[s_i] != t_i){
                        return false;
                    }
                }
            }

            return true;
        }
};

int main(){

    Solution s = Solution();

    string source = "egg";
    string target = "add";
    bool res = s.isIsomorphic(source, target);
    cout << res << endl;

    source = "egg";
    target = "ddd";
    res = s.isIsomorphic(source, target);
    cout << res << endl;

    source = "foo";
    target = "bar";
    res = s.isIsomorphic(source, target);
    cout << res << endl;

    source = "paper";
    target = "title";
    res = s.isIsomorphic(source, target);
    cout << res << endl;

    return 0;
}