#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            if(word1.length() == 0) return word2.length();
            if(word2.length() == 0) return word1.length();

            int len_1 = word1.length() + 1;
            int len_2 = word2.length() + 1;

            vector<vector<int>> grid;
            for(int i = 0; i < len_1; ++i)
            {
                vector<int> grid_son(len_2);
                grid.push_back(grid_son);
            } 

            for(int i = 0; i < len_1; ++i)
            {
                for(int j = 0; j < len_2; ++j)
                {
                    if(i == 0 && j == 0) grid[i][j] = 0;
                    else if(i == 0) grid[i][j] = j;
                    else if(j == 0) grid[i][j] = i;
                    else
                    {
                        //cout<<"Hello: "<<word1[i-1]<<" "<<word2[j-1]<<endl;
                        if(word1[i-1] == word2[j-1])
                        {
                            grid[i][j] = min(grid[i-1][j] + 1, min(grid[i][j-1] + 1, grid[i-1][j-1]));
                        }
                        else
                        {
                            grid[i][j] = min(grid[i-1][j] + 1, min(grid[i][j-1] + 1, grid[i-1][j-1] + 1));
                        }
                    }
                }
            }

            /*for(int i = 0; i < len_1; ++i)
            {
                for(int j = 0; j < len_2; ++j)
                {
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }*/

            return grid[len_1 - 1][len_2 - 1];
        }
};

int main()
{
    Solution s;

    string word1 = "a";
    string word2 = "b";

    int res = s.minDistance(word1, word2);
    cout<<"res: "<<res<<endl;

    return 0;
}