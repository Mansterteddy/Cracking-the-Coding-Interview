#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums){
            
            int index = 0;
            while(index != nums.size()){
                if(nums[index] > 0 && nums[index] <= nums.size() && index != nums[index] - 1 && nums[nums[index] - 1] != nums[index]){
                    swap(nums[index], nums[nums[index] - 1]);
                }
                else{
                    index += 1;
                }
            }

            for(int i = 0; i < nums.size(); ++i){

                if(nums[i] < 0 || i != nums[i] - 1){
                    return i + 1;
                }
            }

            return nums.size() + 1;

        }
};

int main(){

    Solution s = Solution();

    //vector<int> nums{1, 2, 0};
    //vector<int> nums{4, 1, 2, 3};
    //vector<int> nums{3, 4, -1, 1};
    vector<int> nums{1, 1};

    int res = s.firstMissingPositive(nums);
    cout << res << endl;

    return 0;
}