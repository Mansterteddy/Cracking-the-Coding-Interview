#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        map<string, int> roman_map;

        Solution(){
            roman_map["I"] = 1;
            roman_map["V"] = 5;
            roman_map["X"] = 10;
            roman_map["L"] = 50;
            roman_map["C"] = 100;
            roman_map["D"] = 500;
            roman_map["M"] = 1000;
            roman_map["IV"] = 4;
            roman_map["IX"] = 9;
            roman_map["XL"] = 40;
            roman_map["XC"] = 90;
            roman_map["CD"] = 400;
            roman_map["CM"] = 900;
        }

        int romanToInt(string s){

            int res = 0;

            if(s.length() == 0) return res;
            if(s.length() == 1) return roman_map[s];

            int cur_index = 0;
            while(cur_index < s.length()){

                if(cur_index == s.length() - 1){
                    res += roman_map[s.substr(cur_index, 1)];
                    cur_index += 1;
                }
                else{
                    auto map_iter = roman_map.find(s.substr(cur_index, 2));
                    if(map_iter != roman_map.end()){
                        res += map_iter->second;
                        cur_index += 2;
                    }
                    else{
                        res += roman_map[s.substr(cur_index, 1)];
                        cur_index += 1;
                    }
                }
            }
            return res;
        }
};

int main(){

    Solution s = Solution();
    //cout << s.roman_map["I"] << endl;

    string str = "III";
    int res = s.romanToInt(str);
    cout << res << endl;

    str = "IV";
    res = s.romanToInt(str);
    cout << res << endl;

    str = "IX";
    res = s.romanToInt(str);
    cout << res << endl;

    str = "LVIII";
    res = s.romanToInt(str);
    cout << res << endl;

    str = "MCMXCIV";
    res = s.romanToInt(str);
    cout << res << endl;

    return 0;
}