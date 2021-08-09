#include <iostream>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor){
            
            if(dividend == 0) return 0;
            if(divisor == 1) return dividend;
            if(dividend == -2147483648 && divisor == -1) return 2147483647;
            if(divisor == -1) return -dividend;

            int flag = 1;
            if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
                flag = -1;

            long long cur_dividend = dividend;
            cur_dividend = abs(cur_dividend);
            long long long_divisor = abs(divisor);

            if(cur_dividend == long_divisor) return flag;

            int res = 0;

            while(cur_dividend > 0){
                
                if(cur_dividend < long_divisor) break;
                if(cur_dividend == long_divisor){
                    res += 1;
                    break;
                }

                long long cur_divisor = long_divisor;
                long long cur_level = 1;

                while(cur_dividend > cur_divisor){
                    
                    cout << "dividend: " << cur_dividend << " cur_divisor: " << cur_divisor << " cur_level: " << cur_level << endl;
                    cur_dividend -= cur_divisor;
                    res += cur_level;
                    cur_divisor = cur_divisor << 1;
                    cur_level = cur_level << 1;
                }

            }

            return flag * res;
        }
};

int main(){

    Solution s = Solution();

    int dividend = 10;
    int divisor = 3;
    int res = s.divide(dividend, divisor);
    cout << res << endl;

    dividend = 7;
    divisor = -3;
    res = s.divide(dividend, divisor);
    cout << res << endl;

    dividend = 2147483647;
    divisor = 2;
    res = s.divide(dividend, divisor);
    cout << res << endl;

    dividend = -2147483648;
    divisor = 2;
    res = s.divide(dividend, divisor);
    cout << res << endl;

    return 0;
}