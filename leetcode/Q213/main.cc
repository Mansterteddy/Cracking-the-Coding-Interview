#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int rob_list(vector<int>& nums, int start, int length){
        vector<int> res_vec;

        for(int i = 0; i < length; ++i){
            if(i == 0){
                res_vec.push_back(nums[start + i]);
            }
            else if(i == 1){
                res_vec.push_back(max(nums[start], nums[start + 1]));
            }
            else{
                res_vec.push_back(max(res_vec[i-1], res_vec[i-2] + nums[start + i]));
            }
        }

        return res_vec[res_vec.size()-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        return max(rob_list(nums, 1, nums.size() - 1), rob_list(nums, 0, nums.size() - 1));

    }
};

int main(){

    Solution s = Solution();

    vector<int> a{2, 3, 2};
    int res_a = s.rob(a);
    cout << res_a << endl;

    vector<int> b{1, 2, 3, 1};
    int res_b = s.rob(b);
    cout << res_b << endl;

    vector<int> c{0};
    int res_c = s.rob(c);
    cout << res_c << endl;

    return 0;
}