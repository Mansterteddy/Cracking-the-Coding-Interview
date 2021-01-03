#include <iostream>

using namespace std;

class Solution {
    public:
        int climbStairs(int n){
            
            int first_num = 1;
            int second_num = 2;

            if(n==1) return first_num;
            if(n==2) return second_num;

            int res_num = 0;
            for(int i = 3; i <= n; ++i){
                res_num = first_num + second_num;
                first_num = second_num;
                second_num = res_num;
            }

            return res_num;
        }
};

int main(){

    Solution s = Solution();

    int res_a = s.climbStairs(2);
    cout << res_a << endl;

    int res_b = s.climbStairs(3);
    cout << res_b << endl;

    return 0;
}