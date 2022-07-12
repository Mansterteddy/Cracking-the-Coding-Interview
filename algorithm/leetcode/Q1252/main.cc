#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int oddCells(int m, int n, vector<vector<int>>& indices){
            vector<int> row_count(m, 0);
            vector<int> col_count(n, 0);

            for(int i = 0; i < indices.size(); ++i){
                int row = indices[i][0];
                int col = indices[i][1];
                row_count[row] += 1;
                col_count[col] += 1;
            }

            int odd_count = 0;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    int cur_val = row_count[i] + col_count[j];
                    if(cur_val % 2 == 1){
                        odd_count += 1;
                    }
                }
            }

            return odd_count;
        }
};

int main(){

    Solution s = Solution();

    vector<int> a_1{0, 1};
    vector<int> a_2{1, 1};
    vector<vector<int>> a{a_1, a_2};
    int res_1 = s.oddCells(2, 3, a);
    cout << res_1 << endl;

    vector<int> b_1{0, 0};
    vector<int> b_2{1, 1};
    vector<vector<int>> b{b_1, b_2};
    int res_2 = s.oddCells(2, 2, b);
    cout << res_2 << endl;

    return 0;
}