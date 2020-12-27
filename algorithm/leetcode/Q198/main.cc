#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums){
            // 转移方程
            // a[i] = max(a[i-1], a[i-2] + val[i])
            
            if(nums.size() == 0) return 0;
            if(nums.size() == 1) return nums[0];

            vector<int> res_vec;

            for(int i = 0; i < nums.size(); ++i){
                if(i == 0){
                    res_vec.push_back(nums[i]);
                }
                else if(i == 1){
                    res_vec.push_back(max(nums[0], nums[1]));
                }
                else{
                    int val = max(res_vec[i-1], res_vec[i-2] + nums[i]);
                    res_vec.push_back(val);
                }
            }

            return res_vec[res_vec.size()-1];

        }
};

int main(){

    Solution s = Solution();

    vector<int> a{1, 2, 3, 1};
    int res_a = s.rob(a);
    cout << res_a << endl;

    vector<int> b{2, 7, 9, 3,1};
    int res_b = s.rob(b);
    cout << res_b << endl;

    return 0;
}