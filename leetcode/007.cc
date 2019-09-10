#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            long out = 0;

            while (x != 0){
                out = out * 10 + x % 10;
                x = x / 10;
            }

            if (out > INT32_MAX || out < INT32_MIN) return 0;

            return int(out);

        }
};

int main(){
    cout << "LeetCode 007" << endl;

    Solution so = Solution();

    //int a = 123;
    //int a = -123;
    int a = 120;

    int res = so.reverse(a);
    cout << "res: " << res << endl;

    return 0;
}