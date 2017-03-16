//Given a collection of candidate numbers (C) and a target number (T), 
//find all unique combinations in C where the candidate numbers sums to T. 
//All numbers (including target) will be positive integers. 
//The solution set must not contain duplicate combinations. 
//[10, 1, 2, 7, 6, 1, 5] and target 8 
//ans: [1, 7], [1, 2, 5], [2, 6], [1, 1, 6]

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            vector<vector<int>> res;
            sort(candidates.begin(), candidates.end());
            vector<int> local;
            findCombination(res, 0, target, local, candidates);
            return res;
        }

        void findCombination(vector<vector<int>>& res, const int order, const int target, 
        vector<int>& local, const vector<int>& num)
        {
            if(target == 0)
            {
                res.push_back(local);
                return;
            }
            else
            {
                for(int i = order; i < num.size(); ++i)
                {
                    if(num[i] > target) return;
                    if(i && num[i]== num[i-1] && i > order) continue;
                    local.push_back(num[i]);
                    findCombination(res, i+1, target-num[i], local, num);
                    local.pop_back();
                }
            }
        }

};

int main()
{
    Solution s;

    //vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    //int target = 8;    
    
    vector<int> candidates = {3,1,4,4,3,3,5,5};
    int target = 10;

    vector<vector<int>> res = s.combinationSum2(candidates, target);

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