//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int removeDuplicates(vector<int>& nums)
        {
            if(nums.size() == 0 || nums.size() == 1) return nums.size();
            int index_1 = 0;
            int index_2 = 1;
            while(index_2 < nums.size())
            {
                if(nums[index_1] == nums[index_2])
                {
                    index_2++;
                }
                else
                {
                    int temp = nums[index_2];
                    index_1++;
                    nums[index_2] = nums[index_1];
                    nums[index_1] = temp;
                    index_2++;
                }
            }

            return index_1 +1;
        }
};

int main()
{
    Solution s;

    vector<int> arr = {1, 1, 2, 3, 4, 4, 5, 7, 8};
    int res = s.removeDuplicates(arr);
    cout<<"res: "<<res<<endl;

    return 0;
}