//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehad. 
//0, 1, 2, 3, 4, 5, 6, 7 to 4, 5, 6, 7, 0, 1, 2, 3
//You are given a traget value to search. If found in the array return its index, otherwise return -1. 
//You may assume no duplicate exits in the array. 


//O(logn)的时间复杂度，关键在于：a b c d e f g，对于每一个字母，都可以通过和head、end的关系，判断哪边是单调递增的。
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int search(vector<int>& nums, int target)
        {
            int head = 0;
            int end = nums.size() - 1;

            while(head <= end)
            {
                int index = (head + end) / 2;
                if(nums[index] == target)
                {
                    return index;
                }
                else if(nums[index] <= nums[end] && nums[head] <= nums[index])
                {
                    if(nums[index] > target)
                    {
                        end = index - 1;
                    }
                    else
                    {
                        head = index + 1;
                    }
                }
                else if(nums[index] >= nums[end] && nums[index] >= nums[head])
                {
                    if(nums[index] > target)
                    {
                        if(target == nums[head]) return head;
                        else if(target < nums[head]) head = index + 1;
                        else end = index - 1;
                    }
                    else
                    {
                        head = index + 1;
                    }
                }
                else
                {
                    if(nums[index] < target)
                    {
                        if(target == nums[end]) return end;
                        else if(target < nums[end]) head = index + 1;
                        else end = index - 1;
                    }
                    else
                    {
                        end = index - 1;
                    }
                }
            }

            return -1;
        }
};

int main()
{
    Solution s;

    vector<int> a = {4, 5, 6, 7, 8, 1, 2, 3};
    int res = s.search(a, 10);
    cout<<"res: "<<res<<endl;

    return 0;
}
