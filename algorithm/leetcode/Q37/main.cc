#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution{
    public:

        struct compare{
            template<class T>
            bool operator()(T const& a, T const& b) const {return a[2] > b[2];}
        };

        bool recursive_solver(vector<vector<char>>& board,
            vector<unordered_set<int>>& row_info_vec, vector<unordered_set<int>>& col_info_vec, 
                                vector<unordered_set<int>>& mix_info_vec, vector<vector<int>>& candidates, int index){
            
            int cur_row = candidates[index][0];
            int cur_col = candidates[index][1];
            int cur_mix = (cur_row / 3) * 3 + (cur_col) / 3;

            for(int i = 1; i <= 9; ++i){
                if(row_info_vec[cur_row].find(i) == row_info_vec[cur_row].end() && 
                    col_info_vec[cur_col].find(i) == col_info_vec[cur_col].end() && 
                    mix_info_vec[cur_mix].find(i) == mix_info_vec[cur_mix].end()){
                    if(index == candidates.size() - 1){
                        board[cur_row][cur_col] = '1' + i - 1;
                        return true;
                    }
                    else{
                        row_info_vec[cur_row].insert(i);
                        col_info_vec[cur_col].insert(i);
                        mix_info_vec[cur_mix].insert(i);
                        
                        bool res = recursive_solver(board, row_info_vec, col_info_vec, mix_info_vec, candidates, index + 1);

                        if(res == true){
                            board[cur_row][cur_col] = '1' + i - 1;
                            return true;
                        }
                        else{
                            row_info_vec[cur_row].erase(i);
                            col_info_vec[cur_col].erase(i);
                            mix_info_vec[cur_mix].erase(i);
                        }
                    }
                }
            }
            return false;
        }

        void solveSudoku(vector<vector<char>>& board){
            
            vector<unordered_set<int>> row_info_vec;
            vector<unordered_set<int>> column_info_vec;
            vector<unordered_set<int>> mix_info_vec;

            for(int i = 0; i < 9; ++i){
                unordered_set<int> info_set;
                row_info_vec.push_back(info_set);
                column_info_vec.push_back(info_set);
                mix_info_vec.push_back(info_set);
            }
            
            vector<vector<int>> candidates;

            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j){
                    if(board[i][j] == '.'){
                        vector<int> item{i, j};
                        candidates.push_back(item);
                    }
                    else{
                        row_info_vec[i].insert(board[i][j] - '1' + 1);
                        column_info_vec[j].insert(board[i][j] - '1' + 1);
                        mix_info_vec[(i/3)*3+j/3].insert(board[i][j] - '1' + 1);
                    }
                }
            }

            for(int i = 0; i < candidates.size(); ++i){
                int cur_available_value = 0;

                for(int j = 1; j <= 9; ++j){
                    int cur_row = candidates[0][0];
                    int cur_col = candidates[0][1];
                    int cur_mix = (cur_row / 3) * 3 + (cur_col) / 3;
                    
                    if(row_info_vec[cur_row].find(j) == row_info_vec[cur_row].end() &&
                        column_info_vec[cur_col].find(j) == column_info_vec[cur_col].end() &&
                        mix_info_vec[cur_mix].find(j) == mix_info_vec[cur_mix].end()
                        ){
                            cur_available_value += 1;
                        }

                }
                candidates[i].push_back(cur_available_value);
            }

            sort(candidates.begin(), candidates.end(), compare());
            /*for(int i = 0; i < candidates.size(); ++i){
                cout << candidates[i][0] << " " << candidates[i][1] << " " << candidates[i][2] << endl;
            }
            cout << "end init!" << endl;*/

            bool res = recursive_solver(board, row_info_vec, column_info_vec, mix_info_vec, candidates, 0);

            return;

        }
};

int main(){

    Solution s = Solution();

    vector<char> board_1_0{'5','3','.','.','7','.','.','.','.'};
    vector<char> board_1_1{'6','.','.','1','9','5','.','.','.'};
    vector<char> board_1_2{'.','9','8','.','.','.','.','6','.'};
    vector<char> board_1_3{'8','.','.','.','6','.','.','.','3'};
    vector<char> board_1_4{'4','.','.','8','.','3','.','.','1'};
    vector<char> board_1_5{'7','.','.','.','2','.','.','.','6'};
    vector<char> board_1_6{'.','6','.','.','.','.','2','8','.'};
    vector<char> board_1_7{'.','.','.','4','1','9','.','.','5'};
    vector<char> board_1_8{'.','.','.','.','8','.','.','7','9'};

    vector<vector<char>> board_1{board_1_0, board_1_1, board_1_2, board_1_3, board_1_4, board_1_5, board_1_6, board_1_7, board_1_8};
    s.solveSudoku(board_1);

    for(auto item: board_1){
        for(auto subitem: item){
            cout << subitem << " ";
        }
        cout << endl;
    }

    return 0;
}