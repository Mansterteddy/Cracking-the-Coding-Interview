#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{    
    public:
        void recursiveSolver(vector<int> cur_vec, int cur_layer, int n, int& res){

            if(cur_layer == n - 1){
                int cur_index = -1;
                for(int i = 0; i < n; ++i){
                    if(find(cur_vec.begin(), cur_vec.end(), i) == cur_vec.end()){
                        cur_index = i;
                        break;
                    }
                }

                bool flag = true;
                for(int i = 0; i < cur_vec.size(); ++i){
                    if(abs(cur_vec[i] - cur_index) == (cur_layer - i)){
                        flag = false;
                    }
                }

                if(flag){
                    cur_vec.push_back(cur_index);
                    res += 1;
                    cur_vec.pop_back();
                }                
                return;
            }
            else
            {
                for(int i = 0; i < n; ++i){
                    
                    if(find(cur_vec.begin(), cur_vec.end(), i) == cur_vec.end()){
                        
                        int cur_index = i;
                        
                        bool flag = true;
                        for(int i = 0; i < cur_vec.size(); ++i){
                            if(abs(cur_vec[i] - cur_index) == (cur_layer - i)){
                            flag = false;
                            }
                        }
                        
                        if(flag){
                            cur_vec.push_back(cur_index);
                            recursiveSolver(cur_vec, cur_layer+1, n, res);
                            cur_vec.pop_back();
                        }
                    }
                }
            }
        }

        int totalNQueens(int n){

            if(n==1){
                return 1;
            }

            int res = 0;
            for(int i = 0; i < n; ++i){
                vector<int> cur_vec;
                cur_vec.push_back(i);
                recursiveSolver(cur_vec, 1, n, res);
                cur_vec.pop_back();
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    int res = s.totalNQueens(8);
    cout << res << endl;

    return 0;
}