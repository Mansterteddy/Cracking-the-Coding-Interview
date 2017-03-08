//Determine if a Sudoku is valid. 
//The Sudoku board could be partially filled, where empty cells are filled with the character '.' 
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            bool res = true;

            vector<int> handle;

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
                        int val = (int)board[i][j];
                        
                        int han_x = handle[i];
                        int han_x_c = han_x | (1<<val);
                        if(han_x == han_x_c) return false;
                        else handle[i] = han_x_c;

                        int han_y = handle[j + 9];
                        int han_y_c = han_y | (1<<val);
                        if(han_y == han_y_c) return false;
                        else handle[j + 9] = han_y_c;

                        int han_z = handle[18 + j / 3 + (i / 3) * 3];
                        int han_z_c = han_z | (1<<val);
                        if(han_z == han_z_c) return false;
                        else handle[18 + j / 3 + (i / 3) * 3] = han_z_c;
                        //cout<<"x: "<<i<<" y: "<<j + 9<<" z: "<<18 + j / 3 + (i / 3) * 3<<endl;
                        
                    }
                }
            }

            return res;
        }
};

int main()
{
    Solution s;

    vector<char> v1 = {'.', '8', '7', '6', '5', '4', '3', '2', '1'};
    vector<char> v2 = {'2', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v3 = {'3', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v4 = {'4', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v5 = {'5', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v6 = {'6', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v7 = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v8 = {'8', '.', '.', '.', '.', '.', '.', '.', '.'};
    vector<char> v9 = {'9', '.', '.', '.', '.', '.', '.', '.', '.'};

    vector<vector<char>> v = {v1, v2, v3, v4, v5, v6, v7, v8, v9};

    bool res = s.isValidSudoku(v);
    cout<<"res: "<<res<<endl;

    return 0;
}