//Follow up for N-Queens problem. 
//Now, instead outputing board configurations, return the total number of distinct soiutions. 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    int totalNQueens(int n)
    {
            if(n == 0) return 0;

            vector<vector<int>> chess_board_res;

            vector<int> chess_board(n);

            generate(chess_board, 0, n, chess_board_res);

            return chess_board_res.size();

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

    const int n = 8;
    int res = s.totalNQueens(n);
    cout<<"res: "<<res<<endl;

    return 0;
}