#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        bool canJump(vector<int>& nums){
            vector<int> res;
            res.push_back(1);
            for(int i = 1; i < nums.size(); ++i){
                res.push_back(-1);
            }

            for(int i = 0; i < nums.size(); ++i){
                if(res[i] == -1) break;
                else{
                    for(int j = 1; (j<=nums[i]) && (i+j<nums.size()) ; ++j){
                        if(res[i+j] == -1) res[i+j] = 1;
                        if(i+j == nums.size()-1) return true;
                    }
                }
            }

            if(res[res.size()-1] == -1)
                return false;
            else
                return true;
        }
};

int main(){

    Solution s = Solution();

    vector<int> nums_1{2, 3, 1, 1, 4};
    bool res_1 = s.canJump(nums_1);
    cout << res_1 << endl;

    vector<int> nums_2{3, 2, 1, 0, 4};
    bool res_2 = s.canJump(nums_2);
    cout << res_2 << endl;

    return 0;
}