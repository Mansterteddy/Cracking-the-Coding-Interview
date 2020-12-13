#include <vector>
#include <iostream>

using namespace std;

void printMat(vector<vector<int>> mat){

    for(int i = 0; i < mat.size(); ++i){
        for(int j = 0; j < mat[i].size(); ++j){
            cout << mat[i][j] << endl;
        }
    }

}

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            
            int row = grid.size();
            if(row == 0) return 0;

            int col = grid[0].size();
            if(col == 0) return 0;

            vector<int> res_item(col, 0);
            vector<vector<int>> res(row, res_item);

            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[i].size(); ++j){
                    if(i == 0 && j == 0){
                        res[i][j] = grid[i][j];
                    }
                    else if(i == 0){
                        res[i][j] = res[i][j-1] + grid[i][j];
                    }
                    else if(j == 0){
                        res[i][j] = res[i-1][j] + grid[i][j];
                    }
                    else{
                        res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
                    }
                }
            }
            //printMat(res);

            return res[row-1][col-1];

        }
};


int main(){

    Solution s = Solution();

    vector<int> a{1, 3, 1};
    vector<int> b{1, 5, 1};
    vector<int> c{4, 2, 1};

    vector<vector<int>> abc{a, b, c};

    int res = s.minPathSum(abc);
    cout << res << endl;
    
    vector<int> d{1, 2, 3};
    vector<int> e{4, 5, 6};

    vector<vector<int>> de{d, e};

    res = s.minPathSum(de);
    cout << res << endl;

    return 0;
}