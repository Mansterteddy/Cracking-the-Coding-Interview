//Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
//For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//the contiguous subarray [4, -1, 2, 1] has the largest sum = 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;

        vector<int> num(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i == 0)
            {
                num[i] = nums[i];
            }
            else
            {
                num[i] = max(nums[i], num[i-1] + nums[i]);
            }
        }

        int max = num[0];
        for(int i = 1; i < num.size(); ++i)
        {
            if(max < num[i]) max = num[i];
        }

        return max;
    }
};


int main()
{
    Solution s;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = s.maxSubArray(nums);
    cout<<"res: "<<res<<endl;

    return 0;
}