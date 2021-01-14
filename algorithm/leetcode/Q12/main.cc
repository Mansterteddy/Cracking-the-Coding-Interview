#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:

        unordered_map<int, string> roman_map = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, 
            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
        };

        string intToRomanWithRange(int num, int range){
            if(num == 0){
                return "";
            }
            else if(num == 1 || num == 4 || num == 5 || num == 9){
                return roman_map[num * range];
            }
            else if(num < 4){
                string res = "";
                for(int i = 0; i < num; ++i){
                    res += roman_map[1 * range];
                }
                return res;

            }
            else{
                string res = roman_map[5 * range];
                for(int i = 5; i < num; ++i){
                    res += roman_map[1 * range];
                }
                return res;
            }
        }

        string intToRoman(int num) {

            string res = "";

            auto iter = roman_map.find(num);
            if(iter != roman_map.end()){
                return iter->second;
            }

            if(num > 1000){
                int val_1000 = num / 1000;
                num = num % 1000;

                for(int i = 0; i < val_1000; ++i){
                    res += roman_map[1000];
                }
            }
            
            int val_100 = num / 100;
            res += intToRomanWithRange(val_100, 100);

            num = num % 100;
            int val_10 = num / 10;
            res += intToRomanWithRange(val_10, 10);

            num = num % 10;
            res += intToRomanWithRange(num, 1);

            return res;

        }
};

int main(){
    
    Solution s = Solution();

    int num = 3;
    string res = s.intToRoman(num);
    cout << res << endl;
    
    num = 4;
    res = s.intToRoman(num);
    cout << res << endl;

    num = 58;
    res = s.intToRoman(num);
    cout << res << endl;

    num = 1994;
    res = s.intToRoman(num);
    cout << res << endl;
    
    return 0;
    
}


