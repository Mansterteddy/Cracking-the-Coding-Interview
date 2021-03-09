#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstableGrid){

            int m = obstableGrid.size();
            if(m == 0) return 0;
            int n = obstableGrid[0].size();
            if(n == 0) return 0;

            vector<int> prev_vec;
            for(int i = 0; i < n; ++i){
                if(i == 0){
                    if(obstableGrid[0][i] == 0){
                        prev_vec.push_back(1);
                    }
                    else{
                        prev_vec.push_back(0);
                    }
                }
                else{
                    if(prev_vec[i-1] == 0){
                        prev_vec.push_back(0);
                    }
                    else{
                        if(obstableGrid[0][i] == 0){
                            prev_vec.push_back(1);
                        }
                        else{
                            prev_vec.push_back(0);
                        }
                    }
                }
            }

            vector<int> next_vec(n, 0);

            for(int i = 1; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(j == 0){
                        if(prev_vec[0] == 0){
                            next_vec[j] = 0;
                        }
                        else{
                            if(obstableGrid[i][j] == 0){
                                next_vec[j] = 1;
                            }
                            else{
                                next_vec[j] = 0;
                            }
                        }
                    }
                    else{
                        if(obstableGrid[i][j] == 1){
                            next_vec[j] = 0;
                        }
                        else{
                            next_vec[j] = next_vec[j-1] + prev_vec[j];
                        }
                    }
                }
                prev_vec = next_vec;
            }

            return prev_vec[n-1];
        }
};

int main(){

    Solution s = Solution();

    vector<int> a_1{0, 0, 0};
    vector<int> a_2{0, 1, 0};
    vector<int> a_3{0, 0, 0};
    vector<vector<int>> a{a_1, a_2, a_3};

    int res_a = s.uniquePathsWithObstacles(a);
    cout << res_a << endl;

    vector<int> b_1{0, 1};
    vector<int> b_2{0, 0};
    vector<vector<int>> b{b_1, b_2};
    
    int res_b = s.uniquePathsWithObstacles(b);
    cout << res_b << endl;

    return 0;
}