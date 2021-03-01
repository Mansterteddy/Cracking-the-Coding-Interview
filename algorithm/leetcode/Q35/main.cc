#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int searchInsert(vector<int>& nums, int target){

            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == target || nums[i] > target){
                    return i;
                }
            }

            return nums.size();
        }
};

int main(){

    Solution s = Solution();

    vector<int> nums_a{1, 3, 5, 6};
    int res_a = s.searchInsert(nums_a, 5);
    cout << res_a << endl;

    return 0;
}