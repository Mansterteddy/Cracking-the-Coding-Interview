#include <iostream>

using namespace std;

class Solution {
    public:

        double recursive_pow(double x, int n){

            if(n == 1){
                return x;
            }
            else if(n == 2){
                return x * x;
            }
            else{
                
                double cur_val = recursive_pow(x, n / 2);

                if(n % 2 == 0){
                    return cur_val * cur_val;
                }
                else{
                    return cur_val * cur_val * x;
                }

            }

        }


        double myPow(double x, int n){
            
            if(x == 1) return 1.0;
            if(n == 0) return 1.0;

            if(n < 0){
                if(n != -2147483648){
                    x = 1 / x;
                    n = -n;
                }
                else{
                    double res = recursive_pow(1/x, 2147483647) * (1/x);
                    return res;
                }
            }

            double res = recursive_pow(x, n);
            return res;
        }
};

int main(){

    Solution s = Solution();

    double x = 2.0;
    int n = 10;
    double res = s.myPow(x, n);
    cout << res << endl;

    x = 2.1;
    n = 3;
    res = s.myPow(x, n);
    cout << res << endl;

    x = 2.0;
    n = -2;
    res = s.myPow(x, n);
    cout << res << endl;

    x = -1.0;
    n = -2147483648;
    res = s.myPow(x, n);
    cout << res << endl;

    return 0;
}