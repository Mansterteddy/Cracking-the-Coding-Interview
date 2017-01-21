///Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//这道题，为了达到O(n)的时间复杂度，首先遍历整个数组，将数组中每个元素放入Hash Table中，Hash Table中放的是对应元素的位置，随后遍历整个数组，对每一个元素item，
//计算item_b = target - item，查看item_b是否存在于Hash Table中，如果存在，则返回。
//值得注意的是，如果是3 2 4，target = 6，必须处理3 + 3这种情况，也就是检查对应元素item_b的位置是否是item的位置，如果是，则忽略这个结果。
//当然对于3 3 3 2 4 target = 6的这种问题，hash_table[3]不可能包含3个item的位置，只会记录一个item的位置，但是程序仍然work，因为只要遍历到另一个item的位置，就可以return结果。
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty())
        {
            vector<int> res;
            return res;
        }

        vector<int>::iterator it1;
        vector<int>::iterator it2;
        vector<int> res;
        for(it1 = nums.begin(); it1 != nums.end(); it1++)
        {
            for(it2 = it1 + 1; it2 != nums.end(); it2++)
            {
                if(*it1 + *it2 == target)
                {
                    res.push_back(it1 - nums.begin());
                    res.push_back(it2 - nums.begin());
                    return res;
                }
                else if(*it1 + *it2 > target)
                {
                    break;
                }
            }
        }

        return res;
    }
};

class Solution{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            map<int, int> mapping;
            vector<int> res;

            vector<int>::iterator it;
            for(it = nums.begin(); it != nums.end(); it++)
            {
                mapping[*it] = it - nums.begin();
            }
            
            for(it = nums.begin(); it != nums.end(); it++)
            {
                const int gap = target - *it;
                if(mapping.find(gap) != mapping.end() && mapping[gap] != it - nums.begin())
                {
                    res.push_back(it - nums.begin());
                    res.push_back(mapping[gap]);
                    break;
                }
            }
            
            return res;
        }
};

int main()
{
    vector<int> num = {3, 2, 4};
    Solution s1;
    int target = 6;
    vector<int> res = s1.twoSum(num, target);
    cout<<"Ans is "<<endl;
    vector<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++)
    {
        cout<<*it<<" ";
    }

    return 0;
}