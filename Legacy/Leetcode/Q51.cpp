//Given an integer n, return all distinct solutions to the n-queens puzzle. 
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively. 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> res;

            if(n == 0)
            {
                vector<string> res_son;
                res.push_back(res_son);
                return res;
            }

            vector<vector<int>> chess_board_res;

            vector<int> chess_board(n);

            generate(chess_board, 0, n, chess_board_res);


            //cout<<"size: "<<chess_board_res.size()<<endl;
            for(int i = 0; i < chess_board_res.size(); ++i)
            {
                vector<string> res_son;
                for(int j = 0; j < chess_board_res[i].size(); ++j)
                {
                    string res_son_son;
                    for(int k = 0; k < n; ++k)
                    {
                        res_son_son += ".";
                    }
                    res_son_son[chess_board_res[i][j]] = 'Q';
                    res_son.push_back(res_son_son);
                }
                res.push_back(res_son);
            }

            return res;

        }

        bool check(vector<int> chess_board, int cur_row)
        {
            for(int i = 0; i < cur_row; ++i)
            {
                if(chess_board[i] == chess_board[cur_row]) return false;
                else
                {
                    int down = chess_board[cur_row] - chess_board[i];
                    int up = cur_row - i;
                    if(up % down == 0 && (up / down == 1 || up / down == -1)) return false;
                }
            }

            return true;
        }

        void generate(vector<int>& chess_board, int cur_row, int n, vector<vector<int>>& chess_board_res)
        {
            if(cur_row == n - 1)
            {
                for(int i = 0; i < n ; ++i)
                {
                    chess_board[cur_row] = i;
                    bool flag = check(chess_board, cur_row);
                    if(flag) chess_board_res.push_back(chess_board);
                    chess_board[cur_row] = 0;
                }
                return;
            }

            for(int i = 0; i < n; ++i)
            {
                chess_board[cur_row] = i;
                bool flag = check(chess_board, cur_row);
                if(flag) generate(chess_board, cur_row + 1, n, chess_board_res);
                chess_board[cur_row] = 0;
            }
        }

};

int main()
{
    Solution s;

    vector<vector<string>> res = s.solveNQueens(4);

    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<endl;
        }

        cout<<endl;
    }

    return 0;
}