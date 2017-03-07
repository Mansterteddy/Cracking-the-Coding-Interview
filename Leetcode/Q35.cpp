//Given a sorted array and a target value, return the index if the target is found. 
//If not, return the index where it would be if it were inserted in order.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int searchInsert(vector<int>& nums, int target)
        {
            int head = 0;
            int end = nums.size() - 1;

            if(target > *(nums.end()-1)) return nums.size();

            while(head < end)
            {
                int index = (head + end) / 2;
                if(nums[index] == target)
                {
                    return index;
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

            if(target > nums[head]) return head + 1;
            else return head;
        }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 3, 5};
    int target = 0;

    int res = s.searchInsert(nums, target);
    cout<<"res: "<<res<<endl;

    return 0;
}