#include <iostream>

using namespace std;

class Solution{
    public:
        int mySqrt(int x ){
            int64_t res = x / 2;

            if(res == 0) return x;

            while(true){

                if(res * res <= x && (res+1) * (res+1) > x){
                    break;
                }
                else{
                    float next_res = res - (res * res - x) / (2.0 * res);
                    if(next_res == res)
                        res = res - 1;
                    else
                        res = int64_t(next_res);
                }
            }
            return res;
        }
};

int main(){

    Solution s = Solution();

    int res = s.mySqrt(1);
    cout << res << endl;

    return 0;
}
