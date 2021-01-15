//Given a collection of distinct numbers, return all possible permutations 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> res;
            if(nums.size() == 0) return res;
            res = permute_recursive(nums, 0);

            return res;
        }

        vector<vector<int>> permute_recursive(vector<int>& nums, int index)
        {
            vector<vector<int>> res;
            if(index == nums.size() - 1)
            {
                vector<int> res_son = {nums[index]};
                res = {res_son};
                return res;
            }
            else
            {
                for(int i = index; i < nums.size(); ++i)
                {
                    swap(nums[index], nums[i]);
                    vector<vector<int>> res_son = permute_recursive(nums, index + 1);
                    for(int j = 0; j < res_son.size(); ++j)
                    {
                        vector<int> res_son_son = res_son[j];
                        res_son_son.insert(res_son_son.begin(), nums[index]);
                        res.push_back(res_son_son);
                    }
                    swap(nums[index], nums[i]);
                }
            }
            return res;
        }
};


int main()
{
    vector<int> nums = {};
    Solution s;

    vector<vector<int>> res = s.permute(nums);

    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}