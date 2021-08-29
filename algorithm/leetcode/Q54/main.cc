#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void push(vector<vector<int>>& matrix, vector<int>& res, int x, int y, int width, int height){
        if(width <= 0 || height <= 0) return;

        if(width == 1 && height == 1){
            res.push_back(matrix[x][y]);
        }
        else if(width == 1){
            for(int i = 0; i < height; ++i)
                res.push_back(matrix[x + i][y]);
        }
        else if(height == 1){
            for(int i = 0; i < width; ++i)
                res.push_back(matrix[x][y+i]);
        }
        else{
            for(int i = 0; i < width; ++i)
                res.push_back(matrix[x][y+i]);
            for(int i = 1; i < height; ++i)
                res.push_back(matrix[x+i][y+width-1]);
            for(int i = width-2; i >= 0; --i)
                res.push_back(matrix[x+height-1][y+i]);
            for(int i = height-2; i > 0; --i)
                res.push_back(matrix[x+i][y]);
        }
        push(matrix, res, x+1, y+1, width-2, height-2);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();
        
        push(matrix, res, 0, 0, n, m);
        return res;
    }
};

int main(){

    Solution s = Solution();

    vector<int> a{1, 2, 3, 4};
    vector<int> b{5, 6, 7, 8};
    vector<int> c{9, 10, 11, 12};

    vector<vector<int>> input_mat{a, b, c};

    auto res = s.spiralOrder(input_mat);

    for(auto item: res){
        cout << item << " ";
    }

    return 0;
}