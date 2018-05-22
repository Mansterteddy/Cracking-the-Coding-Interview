//Given an array and a value, remove all instances of that value and return the new length. 

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int removeElement(vector<int>& nums, int val)
        {
            if(nums.size() == 0 ) return 0;

            int index_1 = 0;
            int index_2 = nums.size() - 1;

            while(index_1 != index_2)
            {
                if(nums[index_1] == val)
                {
                    int temp = nums[index_1];
                    nums[index_1] = nums[index_2];
                    nums[index_2] = temp;
                    index_2--;
                }
                else
                {
                    index_1++;
                }
            }

            if(nums[index_1] == val) return index_1;
            else return index_1 + 1;
        }
};

int main()
{
    Solution s;

    vector<int> v = {1, 1, 2};
    int res = s.removeElement(v, 1);
    cout<<"res: "<<res<<endl;

    return 0;
}