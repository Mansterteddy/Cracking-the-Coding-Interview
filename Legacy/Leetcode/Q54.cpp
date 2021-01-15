//Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order. 
//Given the following matrix: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//You should return [1, 2, 3, 6, 9, 8, 7, 4, 5]
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            vector<int> res;

            int m = matrix.size();
            if(m == 0) return res;
            int n = matrix[0].size();  
            if(m*n == 0) return res;
            

            push(matrix, res,0, 0, n, m);

            return res;
        }

        void push(vector<vector<int>>& matrix, vector<int>& res, int x, int y, int width, int height)
        {
            if(width <= 0 || height <= 0) return;
            cout<<"width: "<<width<<" height: "<<height<<endl;

            if(width == 1 && height == 1)
            {
                res.push_back(matrix[x][y]);
                return;
            }
            else if(width == 1)
            {
                for(int i = 0; i < height; ++i) res.push_back(matrix[x + i][y + width - 1]);
            }
            else if(height == 1)
            {
                for(int i = 0; i < width; ++i)  res.push_back(matrix[x][y + i]);
            }
            else
            {            
                for(int i = 0; i < width; ++i)  res.push_back(matrix[x][y + i]);
                for(int i = 1; i < height; ++i) res.push_back(matrix[x + i][y + width - 1]);
                for(int i = width-2; i >= 0; --i) res.push_back(matrix[x + height - 1][y + i]);
                for(int i = height-2; i >= 1; --i) res.push_back(matrix[x+i][y]);
            }

        
            //for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
            //cout<<endl;

            push(matrix, res, x + 1, y + 1, width - 2, height - 2);
        }
};

int main()
{
    Solution s;
    vector<int> v1 = {3};
    vector<int> v2 = {2};
    //vector<int> v2 = {5, 6, 7, 8};
    //vector<int> v3 = {9, 10, 11, 12};
    //vector<int> v4 = {13, 14, 15, 16};

    vector<vector<int>> v = {v1, v2};

    vector<int> res = s.spiralOrder(v);

    for(int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";

    return 0;
}