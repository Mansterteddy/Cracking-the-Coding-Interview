#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int minPathSum(vector<vector<int>>& grid)
        {
            if(grid.size() == 0) return 0;
            if(grid[0].size() == 0) return 0;

            vector<vector<int>> res;
            for(int i = 0; i < grid.size(); ++i)
            {
                vector<int> res_son(grid[0].size());
                res.push_back(res_son);
            }

            for(int i = 0; i < grid.size(); ++i)
            {
                for(int j = 0; j < grid[0].size(); ++j)
                {
                    if(i == 0 && j == 0) res[i][j] = grid[i][j];
                    else if(i == 0) res[i][j] = res[i][j-1] + grid[i][j];
                    else if(j == 0) res[i][j] = res[i-1][j] + grid[i][j];
                    else
                    {
                        res[i][j] = ((res[i][j-1] > res[i-1][j]) ? res[i-1][j] : res[i][j-1]) + grid[i][j];
                    }

                }
            }

            /*for(int i = 0; i < res.size(); ++i)
            {
                for(int j = 0; j < res[i].size(); ++j)
                {
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }*/

            return res[grid.size()-1][grid[0].size() - 1];
        }
};

int main()
{
    Solution s;

    vector<int> g_1 = {1, 3, 1};
    vector<int> g_2 = {1, 5, 1};
    vector<int> g_3 = {4, 2, 1};
    vector<vector<int>> g = {g_1, g_2, g_3};

    int res = s.minPathSum(g);
    cout<<"res: "<<res<<endl;

    return 0;
}