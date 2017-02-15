//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero. 

//Tag: Hash Map, Greedy
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> res;
            if(nums.size() < 3) return res;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size() - 2; ++i)
            {
                
                int j = i + 1;
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int k = nums.size() - 1;

                cout<<"res: "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                while(j < k)
                {
                    if(nums[i] + nums[j] + nums[k] < 0)
                    {
                        ++j;
                        while(nums[j] == nums[j - 1] && j < k)
                        {
                            ++j;
                        }
                    }
                    else if(nums[i] + nums[j] + nums[k] > 0)
                    {
                        --k;
                        while(nums[k] == nums[k + 1] && j < k)
                        {
                            --k;
                        }
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[k]});
                        ++j;
                        --k;
                        while(nums[j] == nums[j - 1] && nums[k] == nums[k + 1] && j < k)
                        {
                            ++j;
                        }
                    }
                }
            }
            return res;

        }
};

class Solution1
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            map<int, int> m_1;
            vector<vector<int>> res;
            if(nums.size() < 3) return res;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size(); ++i)
            {
                m_1[nums[i]] = i;
            }

            for(int i = 0; i < nums.size() - 2; ++i)
            {
                if(nums[i] > 0) break; 
                if(i > 0 && nums[i] == nums[i-1]) continue;
                for(int j = i + 1; j < nums.size() - 1; ++j)
                {
                    if(nums[i] + nums[j] > 0) break;
                    if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                    int value = 0 - nums[i] - nums[j];
                    if(m_1[value] > j)
                    {
                        vector<int> res_son;
                        res_son.push_back(nums[i]);
                        res_son.push_back(nums[j]);
                        res_son.push_back(value);
                        res.push_back(res_son);
                    }
                }
            }

            return res;
        }
};

int main()
{
    Solution s;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    //vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> ans = s.threeSum(nums);

    for(int i = 0; i < ans.size(); ++i)
    {
        for(int j = 0; j < ans[0].size(); ++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
