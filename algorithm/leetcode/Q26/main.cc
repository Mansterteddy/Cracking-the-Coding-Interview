#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums){
            if(nums.size() == 0)
                return 0;

            int i = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(nums[j] != nums[i]){
                    i++;
                    nums[i] = nums[j];
                }
            }

            return i+1;

        }
};

int main(){

    Solution s = Solution();

    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int res = s.removeDuplicates(nums);
    cout << res << endl;
    for(int i = 0; i < res; ++i){
        cout << nums[i] << endl;
    }

    return 0;
}