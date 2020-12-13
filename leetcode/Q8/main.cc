#include <iostream>
#include <climits>

using namespace std;

class Solution{
    public:
        int myAtoi(string str){
            
            if(str.length() == 0) return 0;
            
            int64_t longRes = 0;

            string chars = " ";
            str = str.erase(0, str.find_first_not_of(chars));

            bool neg = false;
            if(str[0] == '-'){
                neg = true;
                str = str.substr(1, str.length() - 1);
            } else if (str[0] == '+'){
                str = str.substr(1, str.length() - 1);
            }

            int i = 0;
            while (i < str.length()){
                if (longRes > INT32_MAX){
                    if (neg) return INT32_MIN;
                    if (!neg) return INT32_MAX;
                }
                char c = str[i];
                if(c >= '0' && c <= '9'){
                    longRes = longRes * 10 + (c - '0');
                } else break;
                i++;
            }

            longRes = neg ? longRes * (-1) : longRes;

            if (longRes > INT32_MAX){
                return INT32_MAX;
            } else if (longRes < INT32_MIN){
                return INT32_MIN;
            }

            return int(longRes);
        }
};

int main(){

    cout << "LeetCode 008" << endl;

    Solution so = Solution();

    string a = "42";
    int res_a = so.myAtoi(a);
    cout << "res: " << res_a << endl;

    string b = "    -42";
    int res_b = so.myAtoi(b);
    cout << "res: " << res_b << endl;

    string c = "4193 with words";
    int res_c = so.myAtoi(c);
    cout << "res: " << res_c << endl;

    string d = "words and 987";
    int res_d = so.myAtoi(d);
    cout << "res: " << res_d << endl;

    string e = "-91283472332";
    int res_e = so.myAtoi(e);
    cout << "res: " << res_e << endl;

    return 0;

}