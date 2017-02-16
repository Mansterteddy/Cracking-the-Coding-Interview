//Given an array S of n integers, are there elements a, b, c and d in S such that a + b + c + d = target?
//Find all unique quadruplets in the array which gives the sum of target. 

//Tag: Greedy
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            vector<vector<int>> res;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size(); ++i)
            {
                if(i > 0 && nums[i-1] == nums[i]) continue;
                for(int j = i + 1; j < nums.size(); ++j)
                {
                    if(j > i + 1 && nums[j-1] == nums[j]) continue;
                    int index_1 = j + 1;
                    int index_2 = nums.size() - 1;
                    while(index_1 < index_2)
                    {
                        if(nums[i] + nums[j] + nums[index_1] + nums[index_2] < target)
                        {
                            index_1++;
                            while(nums[index_1] == nums[index_1 - 1] && index_1 < index_2)
                            {
                                index_1++;
                            }
                        }
                        else if(nums[i] + nums[j] + nums[index_1] + nums[index_2] > target)
                        {
                            index_2--;
                            while(nums[index_2] == nums[index_2 + 1] && index_1 < index_2)
                            {
                                index_2--;
                            }
                        }
                        else
                        {
                            vector<int> res_son = {nums[i], nums[j], nums[index_1], nums[index_2]};
                            res.push_back(res_son);
                            index_1++;
                            index_2--;
                            while(nums[index_1] == nums[index_1 - 1] && nums[index_2] == nums[index_2 + 1] && index_1 < index_2)
                            {
                                index_1++;
                            }
                        }
                    }

                }
            }

            return res;
        }
};

int main()
{
    Solution s;

    vector<int> nums = {-2, 0, 0, 3, 3, -1};
    const int target = 5;
    vector<vector<int>> res = s.fourSum(nums, target);

    for(int o = 0; o < res.size(); ++o)
    {
        for(int p = 0; p < res[0].size(); ++p)
        {
            cout<<res[o][p]<<" ";
        }
        cout<<endl;
    }

    return 0;
}