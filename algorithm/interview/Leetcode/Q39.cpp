//Given a set of candidate numbers (C) (without duplicates) and a target number(T),
//find all unique combinations in C where the candidate numbers sum to T. 
//The same repeated number may be chosen from C unlimited number of times
//All numbers (including target) will be positive integers. 
//The solution set must not contain duplicate combinations. 
//[2, 3, 6, 7] and target 7
//res: [7], [2, 2, 3]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target)
        {
            vector<vector<vector<vector<int>>>> dp;

            vector<vector<int>> res;

            sort(candidates.begin(), candidates.end());

            if(target < *candidates.begin()) return res;

            for(int i = 0; i < candidates.size(); ++i)
            {
                vector<vector<vector<int>>> dp_son;
                for(int j = *(candidates.begin()); j <= target; ++j)
                {
                    if(candidates[i] == j)
                    {
                        vector<int> dp_eq = {j};
                        vector<vector<int>> dp_son_son = {dp_eq};
                        dp_son.push_back(dp_son_son);
                    }
                    else
                    {
                        vector<vector<int>> dp_son_son;
                        dp_son.push_back(dp_son_son);
                    }
                }
                dp.push_back(dp_son);
            }

            for(int i = 0; i < dp.size(); ++i)
            {
                for(int j = 0; j < dp[i].size(); ++j)
                {
                    if(dp[i][j].size() != 0)
                    {
                        continue;
                    }
                    else
                    {
                        cout<<"Enter None! i: "<<i<<" j: "<<j + *(candidates.begin())<<" candidates: "<<candidates[i]<<endl;
                        if(candidates[i] == j + *(candidates.begin()))
                        {
                            cout<<"Enter equal!"<<endl;
                            vector<int> dp_eq = {candidates[i]};
                            vector<vector<int>> dp_son = {dp_eq};
                            dp[i][j] = dp_son;
                        }
                        else if(candidates[i] > j + *(candidates.begin()))
                        {
                            cout<<"Enter large!"<<endl;
                            continue;
                        }
                        else
                        {
                            cout<<"Enter less!"<<endl;
                            vector<vector<int>> dp_son;
                            for(int k = i; k >= 0; --k)
                            {
                                cout<<"k: "<<k<<" second: "<<j - candidates[i]<<endl;
                                if(j - candidates[i] < 0) break;
                                vector<vector<int>> dp_pre = dp[k][j - candidates[i]];
                                if(dp_pre.size() != 0)
                                {
                                    cout<<"enter!"<<endl;
                                    for(int l = 0; l < dp_pre.size(); ++l)
                                    {
                                        vector<int> dp_pre_son = dp_pre[l];
                                        dp_pre_son.push_back(candidates[i]);
                                        dp_son.push_back(dp_pre_son);
                                    }
                                } 
                            }
                            dp[i][j] = dp_son;
                        }
                    }
                }
            }


            for(int w = 0; w < dp.size(); ++w)
            {
                for(int x = 0; x < dp[w].size(); ++x)
                {
                    for(int y = 0; y < dp[w][x].size(); ++y)
                    {
                        for(int z = 0; z < dp[w][x][y].size(); ++z)
                        {
                            cout<<dp[w][x][y][z]<<" ";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
            }


            for(int i = 0; i < dp.size(); ++i)
            {
                vector<vector<int>> res_son = dp[i][target - *(candidates.begin())];
                for(int j = 0; j < res_son.size(); ++j)
                {
                    res.push_back(res_son[j]);
                }
            }

            return res;

        }

};

int main()
{
    Solution s;

    //vector<int> candidates = {2, 3, 6, 7};
    //int target = 8;

    vector<int> candidates = {1};
    int target = 2;

    vector<vector<int>> res = s.combinationSum(candidates, target);

    cout<<"Res: "<<endl;
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