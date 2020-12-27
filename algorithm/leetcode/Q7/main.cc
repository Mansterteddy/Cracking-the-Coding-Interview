#include <iostream>

using namespace std;

// class Solution {
//     public:
//         int reverse(int x){
            
//             long res = 0;
//             bool flag = false;
//             if(x < 0){
//                 flag = true;
//                 x = abs(x);
//             }

//             while(x != 0){
//                 int a = x % 10;
//                 int b = x / 10;
//                 res *= 10;
//                 res += a;
//                 x = b;
//             }

//             if(flag)
//                 res = -1 * res;

//             if (res > INT32_MAX || res < INT32_MIN) return 0;

//             return int(res);
//         }
// };

class Solution {
    public:
        int reverse(int x) {
            int64_t out = 0;

            while (x != 0){
                out = out * 10 + x % 10;
                x = x / 10;
            }

            if (out > INT32_MAX || out < INT32_MIN) return 0;

            return int(out);

        }
};

int main(){

    Solution s = Solution();

    int a = 123;
    int res = s.reverse(a);
    cout << res << endl;

    int b = -123;
    res = s.reverse(b);
    cout << res << endl;
    
    int c = 120;
    res = s.reverse(c);
    cout << res << endl;

    int d = 1534236469;
    res = s.reverse(d);
    cout << res << endl;

    return 0;

}