#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {

            vector<vector<int>> res_mat;

            for(int i = 0; i < m; ++i){
                vector<int> res_vec;
                for(int j = 0; j < n; ++j){
                    if(i == 0 || j == 0)
                        res_vec.push_back(1);
                    else
                        res_vec.push_back(0);
                }
                res_mat.push_back(res_vec);
            }

            for(int i = 1; i < m; ++i){
                for(int j = 1; j < n; ++j){
                    res_mat[i][j] = res_mat[i-1][j] + res_mat[i][j-1];
                }
            }

            return res_mat[m-1][n-1];
        }
};

class Solution1 {
    public:
        int uniquePaths(int m, int n) {
            
            // 机器人始终需要走m+n-2步，只要保证m-1步是向下走的，就一定可以到达终点，即C(m+n-2, m-1).

            if (m == 1 || n == 1) return 1;

            int first = max(m-1, n-1);
            int second = min(m-1, n-1);

            double a = 1;
            for(int i = first + 1; i <= first + second; i++)
                a *= i;

            double b = 1;
            for(int j = 1; j <= second; j++)
                b *= j;

            return a / b;

        }
};

int main() {

    cout << "Leetcode Q62" << endl;

    Solution1 s = Solution1();

    int res = s.uniquePaths(3, 7);
    cout << res << endl;

    return 0;
}