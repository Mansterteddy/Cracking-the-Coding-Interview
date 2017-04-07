#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool canJump(vector<int>& nums)
        {
            if(nums.size() == 0) return true;

            int max = nums[0];
            for(int i = 1; i < nums.size(); ++i)
            {
                if(max < i) return false;
                int gap = i + nums[i];
                if(max < gap) max = gap;
            }
            return true;
        }
};

int main()
{
    Solution s;

    vector<int> nums = {2, 3, 1, 1, 4};
    bool res = s.canJump(nums);
    cout<<"res: "<<res<<endl;

    nums = {3, 2, 1, 0, 4};
    res = s.canJump(nums);
    cout<<"res: "<<res<<endl;

    return 0;
}