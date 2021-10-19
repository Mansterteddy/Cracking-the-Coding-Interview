#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int singleNumber(vector<int>& nums){
            
            int res = nums[0];
            for(int i = 1; i < nums.size(); ++i){
                res ^= nums[i];
            }

            return res;

        }
};


int main(){

    Solution s = Solution();

    vector<int> a{2, 2, 1};
    auto res_a = s.singleNumber(a);
    cout << res_a << endl;

    vector<int> b{4, 1, 2, 1, 2};
    auto res_b = s.singleNumber(b);
    cout << res_b << endl;

    return 0;
}