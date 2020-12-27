//You are given an n*n 2D matrix representing an image. Rotate the image by 90 degrees(clockwise)
//Could youn do this in-place?

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            int n = matrix.size();
            int a= 0;
            int b = n - 1;
            while(a < b)
            {
                for(int i = 0; i < (b - a); ++i)
                {
                    swap(matrix[a][a+i], matrix[a+i][b]);
                    swap(matrix[a][a+i], matrix[b][b-i]);
                    swap(matrix[a][a+i], matrix[b-i][a]);
                }
                ++a;
                --b;
            }
        }
}

class Solution1
{
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = i; j < matrix.size(); ++j)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }

            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = 0; j < matrix.size() / 2; ++j)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                    matrix[i][matrix.size() - 1 - j] = temp;
                }
            }

            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = 0; j < matrix.size(); ++j)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    //vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    Solution s;
    s.rotate(mat);
    return 0;
}