#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        
        bool first_row = false;
        bool first_column = false;

        for(int i = 0; i < row_count; i++){
            if(matrix[i][0] == 0){
                first_row = true;
                break;
            }
        }

        for(int i = 0; i < col_count; i++){
            if(matrix[0][i] == 0){
                first_column = true;
                break;
            }
        }

        for(int i = 1; i < row_count; i++){
            for(int j = 1; j < col_count; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < row_count; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < col_count; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < col_count; i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < row_count; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(first_row){
            for(int i = 0; i < row_count; ++i){
                matrix[i][0] = 0;
            }
        }

        if(first_column){
            for(int i = 0; i < col_count; ++i){
                matrix[0][i] = 0;
            }
        }

    }
};

int main(){

    Solution s = Solution();

    vector<int> a_1{1, 1, 1};
    vector<int> a_2{1, 0, 1};
    vector<int> a_3{1, 1, 1};
    vector<vector<int>> a{a_1, a_2, a_3};
    s.setZeroes(a);
    for(auto item: a){
        for(auto subitem: item){
            cout << subitem << " ";
        }
        cout << endl;
    }

    vector<int> b_1{0, 1, 2, 0};
    vector<int> b_2{3, 4, 5, 2};
    vector<int> b_3{1, 3, 1, 5};
    vector<vector<int>> b{b_1, b_2, b_3};
    s.setZeroes(b);
    for(auto item: b){
        for(auto subitem: item){
            cout << subitem << " ";
        }
        cout << endl;
    }

    return 0;
}