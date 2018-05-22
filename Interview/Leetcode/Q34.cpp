//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value. 
//If the target is not found in the array, return [-1, -1]
//Given [5, 7, 7, 8, 8, 10] and target value 8
//return [3, 4]

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            int head = 0;
            int end = nums.size() - 1;
            vector<int> res;

            if(nums.size() == 0)
            {
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }

            if(target < nums[0] || target > *(nums.end()-1)) 
            {   
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }

            while(head <= end)
            {
                int index = (head + end) / 2;
                if(nums[index] == target)
                {
                    int start = index;
                    int end = index;

                    while(start >= 0 && nums[start] == target)
                    {
                        start--;
                    }
                    while(end < nums.size() && nums[end] == target)
                    {
                        end++;
                    }
                    res.push_back(start+1);
                    res.push_back(end-1);
                    return res;
                }
                else if(nums[index] > target)
                {
                    end = index - 1;
                }
                else
                {
                    head = index + 1;
                }
            }

            res.push_back(-1);
            res.push_back(-1);
            return res;

        }
};


int main()
{
    Solution s;

    vector<int> nums = {0, 0, 0, 1, 2, 3};
    vector<int> res = s.searchRange(nums, 0);
    for(int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}