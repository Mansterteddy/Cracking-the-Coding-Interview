///Given an array of integers, return indices of the two numbers such that they add up to a specific target.
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