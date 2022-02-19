#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:

        int rowBinarySearch(int val, int left, int right, vector<vector<int>>& matrix){

            if(left == right) return left;
            if(matrix[left][0] > val) return -1;
            if(matrix[right][0] < val) return right;

            while(left <= right){

                if(left == right) return left;

                if(matrix[left][0] == val) return left;
                if(matrix[right][0] == val) return right;

                if(matrix[left][0] < val && matrix[left+1][0] > val) return left;
                if(matrix[right][0] > val && matrix[right-1][0] <= val) return right-1;

                int mid = (left + right) / 2;
                if(matrix[mid][0] <= val && matrix[mid+1][0] > val) return mid;
                if(matrix[mid][0] < val) left = mid + 1;
                else right = mid - 1;
            }

            return left;
        }

        int colBinarySearch(int val, int left, int right, vector<int>& vec){

            if(left > right) return -1;

            if(left == right){
                if(vec[left] == val) return left;
                else return -1;
            }

            if(vec[left] > val) return -1;
            if(vec[right] < val) return -1;

            if(vec[left] == val) return left;
            if(vec[right] == val) return right;

            int mid = (left + right) / 2;
            if(vec[mid] == val) return mid;

            if(vec[mid] > val) return colBinarySearch(val, left, mid-1, vec);
            else return colBinarySearch(val, mid+1, right, vec);
        }

        bool searchMatrix(vector<vector<int>>& matrix, int target){
            bool res = false;
            
            int m = matrix.size();
            if(m == 0) return res;
            int n = matrix[0].size();
            if(n == 0) return res;

            int index_1 = rowBinarySearch(target, 0, m - 1, matrix);
            if(index_1 == -1) return res;
            if(matrix[index_1][0] == target) return true;
            if(target > matrix[index_1][n-1]) return res;

            int index_2 = colBinarySearch(target, 0, n - 1, matrix[index_1]);
            if(index_2 == -1){
                return res;
            }
            else{
                return true;
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    vector<int> a{1, 3, 5, 7};
    vector<int> b{10, 11, 16, 20};
    vector<int> c{23, 30, 34, 60};
    vector<vector<int>> mat{a, b, c};

    bool res_1 = s.searchMatrix(mat, 3);
    cout << res_1 << endl;

    bool res_2 = s.searchMatrix(mat, 13);
    cout << res_2 << endl;

    bool res_3 = s.searchMatrix(mat, 30);
    cout << res_3 << endl;

    return 0;
}