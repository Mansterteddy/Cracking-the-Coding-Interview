#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{

    public:

        bool isValidSudoku(vector<vector<char>>& board){
            vector<unordered_set<char>> row_vector;
            vector<unordered_set<char>> column_vector;
            vector<unordered_set<char>> mid_vector;

            for(int i = 0; i < 9; ++i){
                unordered_set<char> temp_set;
                row_vector.push_back(temp_set);
                column_vector.push_back(temp_set);
                mid_vector.push_back(temp_set);
            }

            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[i].size(); ++j){
                    
                    char cur_item = board[i][j];
                    if(cur_item == '.') continue;

                    auto row_item = &(row_vector[i]);
                    //cout << row_item.size() << endl;

                    if(row_item->find(cur_item) != row_item->end()){
                        return false;
                    }
                    else{
                        row_item->insert(cur_item);
                    }

                    auto column_item = &(column_vector[j]);
                    if(column_item->find(cur_item) != column_item->end()){
                        return false;
                    }
                    else{
                        column_item->insert(cur_item);
                    }

                    auto mid_item = &(mid_vector[(i / 3) * 3 + j / 3]);
                    if(mid_item->find(cur_item) != mid_item->end()){
                        return false;
                    }
                    else{
                        mid_item->insert(cur_item);
                    }
                }
            }

            return true;
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

    bool res_1 = s.isValidSudoku(board_1);
    cout << "res_1: " << res_1 << endl;

    vector<char> board_2_0{'8','3','.','.','7','.','.','.','.'};
    vector<char> board_2_1{'6','.','.','1','9','5','.','.','.'};
    vector<char> board_2_2{'.','9','8','.','.','.','.','6','.'};
    vector<char> board_2_3{'8','.','.','.','6','.','.','.','3'};
    vector<char> board_2_4{'4','.','.','8','.','3','.','.','1'};
    vector<char> board_2_5{'7','.','.','.','2','.','.','.','6'};
    vector<char> board_2_6{'.','6','.','.','.','.','2','8','.'};
    vector<char> board_2_7{'.','.','.','4','1','9','.','.','5'};
    vector<char> board_2_8{'.','.','.','.','8','.','.','7','9'};

    vector<vector<char>> board_2{board_2_0, board_2_1, board_2_2, board_2_3, board_2_4, board_2_5, board_2_6, board_2_7, board_2_8};

    bool res_2 = s.isValidSudoku(board_2);
    cout << "res_2: " << res_2 << endl;

    return 0;
}