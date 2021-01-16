#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle){
            int tree_height = triangle.size();

            vector<int> prev_vec{triangle[0][0]};

            for(int i = 1; i < tree_height; ++i){
                
                // for(int k = 0; k < prev_vec.size(); ++k){
                //     cout << prev_vec[k] << " ";
                // }
                // cout << endl;

                int cur_width = i + 1;

                vector<int> cur_vec;

                for(int j = 0; j < cur_width; ++j){
                    if(j == 0){
                        int cur_val = prev_vec[0] + triangle[i][j];
                        cur_vec.push_back(cur_val);
                    }
                    else if(j == cur_width - 1){
                        int cur_val = prev_vec[prev_vec.size()-1] + triangle[i][j];
                        cur_vec.push_back(cur_val);
                    }
                    else{
                        int first_val = prev_vec[j-1] + triangle[i][j];
                        int second_val = prev_vec[j] + triangle[i][j];
                        int cur_val = min(first_val, second_val);
                        cur_vec.push_back(cur_val);
                    }
                }

                prev_vec = cur_vec;
            }

            int res = prev_vec[0];

            for(int i = 0; i < prev_vec.size(); ++i){
                if(prev_vec[i] < res){
                    res = prev_vec[i];
                }
            }

            return res;

        }
};

int main(){

    Solution s = Solution();

    vector<int> a{2};
    vector<int> b{3, 4};
    vector<int> c{6, 5, 7};
    vector<int> d{4, 1, 8, 3};

    vector<vector<int>> input{a, b, c, d};
    int res = s.minimumTotal(input);

    cout << res << endl;

    return 0;
}