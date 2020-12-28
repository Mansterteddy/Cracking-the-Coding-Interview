#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix){
            
            for(int i = 0; i < matrix.size(); ++i){
                for(int j = i; j < matrix.size(); ++j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            
            for(int i = 0; i < matrix.size(); ++i){
                for(int j = 0; j < matrix.size() / 2; ++j){
                    swap(matrix[i][j], matrix[i][matrix.size()-1-j]);
                }
            }

        }
};

int main(){

    Solution s = Solution();

    vector<int> a_1{1, 2, 3};
    vector<int> a_2{4, 5, 6};
    vector<int> a_3{7, 8, 9};
    vector<vector<int>> a{a_1, a_2, a_3};

    s.rotate(a);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[i].size(); ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}