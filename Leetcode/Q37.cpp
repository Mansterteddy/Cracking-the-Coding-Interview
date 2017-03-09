//Write a program to solve a Sudoku puzzle by filling the empty cells. 
//Empty cells are indicated by the character '.'
//You may assume that there will be only one unique solution. 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        void solveSudoku(vector<vector<char>>& board)
        {
            vector<int> handle;
            vector<int> index;
            
            for(int i = 0; i < 27; ++i)
            {
                handle.push_back(0);
            }

             for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    if(board[i][j] != '.')
                    {
                        int val = (int)(board[i][j]-48);
                        
                        handle[i] |= (1<<val);

                        handle[j + 9] |= (1<<val);

                        handle[18 + j / 3 + (i / 3) * 3] |= (1<<val);
                        
                    }
                    else 
                    {
                        index.push_back(i * 9 + j);
                    }

                }
            }

            bool res = solve(board, index, handle, 0);
            return;
        }

        bool solve(vector<vector<char>>& board, vector<int> index, vector<int>& handle, int count)
        {
            if(count == index.size()) return true;
                
            int i = index[count] / 9;
            int j = index[count] % 9;
            int han_x = handle[i];
            int han_y = handle[j + 9];
            int han_z = handle[18 + j / 3 + (i / 3) * 3];
            
            for(int k = 1; k <= 9; ++k)
            {
                int val = 1<<k;

                if(((val | han_x) != han_x) && ((val | han_y) != han_y) && ((val | han_z) != han_z))
                {
                    board[i][j] = (char)(k+48);
                    handle[i] |= val;
                    handle[j + 9] |= val;
                    handle[18 + j / 3 + (i / 3) * 3] |= val;

                    bool res = solve(board, index, handle, count + 1);
                    if(res) 
                    {
                        return true;
                    }
                    else
                    {
                        board[i][j] = '.';
                        handle[i] = han_x;
                        handle[j + 9] = han_y;
                        handle[18 + j / 3 + (i / 3) * 3] = han_z;
                    }
                }

            }
            
            return false;
        }
};

int main()
{
    vector<char> v1 = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    vector<char> v2 = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v3 = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    vector<char> v4 = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    vector<char> v5 = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    vector<char> v6 = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    vector<char> v7 = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    vector<char> v8 = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    vector<char> v9 = {'.', '.', '.', '2', '7', '5', '9', '.', '.'};

    vector<vector<char>> v = {v1, v2, v3, v4, v5, v6, v7, v8, v9};

    Solution s;

    s.solveSudoku(v);

    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}