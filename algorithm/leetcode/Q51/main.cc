#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{    
    public:
        void recursiveSolver(vector<int> cur_vec, int cur_layer, int n, vector<vector<string>>& res, vector<string>& template_vec){

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
                    vector<string> cur_res = template_vec;
                    for(int i = 0; i < n; ++i){
                        cur_res[i][cur_vec[i]] = 'Q';
                    }
                    res.push_back(cur_res);
                    cur_vec.pop_back();
                }                
                return;
            }
            else{
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
                            recursiveSolver(cur_vec, cur_layer+1, n, res, template_vec);
                            cur_vec.pop_back();
                        
                        }
                    }
                }
            }
        }

        vector<vector<string>> solveNQueens(int n){

            if(n==1){
                vector<string> res_item{"Q"};
                vector<vector<string>> res{res_item};
                return res;
            }

            vector<vector<string>> res;
            vector<string> template_vec;
            string temp_vec_item = "";
            for(int i = 0; i < n; ++i){
                temp_vec_item += ".";
            }
            for(int i = 0; i < n; ++i){
                template_vec.push_back(temp_vec_item);
            }

            for(int i = 0; i < n; ++i){
                vector<int> cur_vec;
                cur_vec.push_back(i);
                recursiveSolver(cur_vec, 1, n, res, template_vec);
                cur_vec.pop_back();
            }

            return res;
        }
};

int main(){

    Solution s = Solution();
    vector<vector<string>> res = s.solveNQueens(4);

    for(auto item: res){
        for(auto item_str: item){
            cout << item_str << endl;
        }
        cout << endl;
    }

    return 0;
}