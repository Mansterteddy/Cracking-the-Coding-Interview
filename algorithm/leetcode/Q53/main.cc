#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums){
            
            int res = nums[0];
            int last_val = nums[0];
            for(int i = 1; i < nums.size(); ++i){
                if(last_val <= 0){
                    if(nums[i] > res)
                        res = nums[i];
                    last_val = nums[i];
                }
                else{
                    int cur_val = last_val + nums[i];
                    if(cur_val >= res)
                        res = cur_val;
                    last_val = cur_val;
                }
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums{-2, 1};
    int res = s.maxSubArray(nums);
    cout << res << endl;

    return 0;
}