#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void gen(vector<vector<int>>& mat, int start_x, int start_y, int count, int val){

        if(count == 0) return;
        if(count == 1){
            mat[start_x][start_y] = val;
            return;
        }

        for(int i = 0; i < count; ++i){
            mat[start_x][start_y+i] = val;
            val += 1;
        }

        for(int i = 1; i < count; ++i){
            mat[start_x+i][start_y+count-1] = val;
            val += 1;
        }

        for(int i = count-2; i >= 0; --i){
            mat[start_x+count-1][start_y+i] = val;
            val += 1;
        }

        for(int i = count-2; i > 0; --i){
            mat[start_x+i][start_y] = val;
            val += 1;
        }

        gen(mat, start_x+1, start_y+1, count-2, val);

    }


    vector<vector<int>> generateMatrix(int n) {
        vector<int> res_item(n, 0);
        vector<vector<int>> res(n, res_item);
        gen(res, 0, 0, n, 1);
        return res;
    }
};

int main(){

    Solution s = Solution();

    auto res_1 = s.generateMatrix(1);
    for(auto vec: res_1){
        for(auto item: vec){
            cout << item << " ";
        }
        cout << endl;
    }
    
    auto res_2 = s.generateMatrix(3);
    for(auto vec: res_2){
        for(auto item: vec){
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
