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
            if(num == 1 || num == 4 || num == 5 || num == 9){
                return roman_map[num * range];
            }
            else if(num < 4){
                string res = roman_map[1 * range];
                for(int i = 1; i < num; ++i){
                    res += res;
                }
                return res;

            }
            else{
                string res = roman_map[5 * range] + roman_map[1 * range];
                for(int i = 6; i <= num; ++i){
                    res += res;
                }
                return res
            }
        }

        string intToRoman(int num) {

            string res = "";

            auto iter = roman_map.find(num);
            if(iter != roman_map.end()){
                return iter->second;
            }

            if(num > 1000){
                int left = num % 1000;
                int val = num / 1000;

            }
            else{
                int val_100 = num / 100;



                int left_100 = num % 100;


            }



            return res;

        }
};

int main(){
    
    Solution s = Solution();

    int num = 3;
    string res = s.intToRoman(num);
    cout << res << endl;
    
    
    return 0;
    
}


