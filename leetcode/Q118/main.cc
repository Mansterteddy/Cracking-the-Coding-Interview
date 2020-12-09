#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            vector<vector<int>> res;

            vector<int> layer_1{1};
            vector<int> layer_2{1, 1};

            if(numRows == 0){
                return res;
            }
            else if(numRows == 1){
                res.push_back(layer_1);
                return res;
            }
            else if(numRows == 2){
                res.push_back(layer_1);
                res.push_back(layer_2);
                return res;
            }

            res.push_back(layer_1);
            res.push_back(layer_2);
            for(int i = 2; i < numRows; ++i){
                vector<int> cur_layer;
                cur_layer.push_back(1);
                for(int j = 1; j < i; ++j){
                    vector<int> prev_layer = res[res.size()-1];
                    int cur_val = prev_layer[j-1] + prev_layer[j];
                    cur_layer.push_back(cur_val);
                }
                cur_layer.push_back(1);
                res.push_back(cur_layer);
            }
            
            return res;

        }
};

int main(){

    cout << "LeetCode 118" << endl;

    Solution s = Solution();

    int numRows = 5;
    auto res = s.generate(numRows);

    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}