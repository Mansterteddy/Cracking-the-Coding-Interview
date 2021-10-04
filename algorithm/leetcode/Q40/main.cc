#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
    public:

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target){

            sort(candidates.begin(), candidates.end());

            vector<vector<int>> init_vec;
            vector<vector<vector<int>>> res_tensor(target+1, init_vec);

            if(candidates.size() == 0) return init_vec;
            if(target < candidates[0]) return init_vec;


            vector<int> zero_init_vec(0);
            res_tensor[0].push_back(zero_init_vec);

            vector<int> first_init_vec(1, candidates[0]);
            res_tensor[candidates[0]].push_back(first_init_vec);

            int prev_val = candidates[0];
            int pre_count = 1;

            for(int i = 1; i < candidates.size(); ++i){
                if(candidates[i] != prev_val){
                    
                    for(int j = candidates[i]; j <= target; ++j){
                        if(res_tensor[j-candidates[i]].size() != 0){
                            for(auto item: res_tensor[j-candidates[i]]){
                                
                                if(item.size() == 0){
                                    item.push_back(candidates[i]);
                                    res_tensor[j].push_back(item);
                                }
                                else{
                                    if(item[item.size()-1] != candidates[i]){
                                        item.push_back(candidates[i]);
                                        res_tensor[j].push_back(item);
                                    }
                                }
                            }
                        }
                    }
                    prev_val = candidates[i];
                    pre_count = 1;
                }
                else{
                    
                    for(int j = candidates[i]+1; j <= target; ++j){
                        if(res_tensor[j-candidates[i]].size() != 0){
                            for(auto item: res_tensor[j-candidates[i]]){
                                bool flag = false;

                                int count_from_bottom = 0;
                                for(int k = item.size() - 1; k >= 0; --k){
                                    if(item[k] != candidates[i]){
                                        break;
                                    }
                                    else{
                                        count_from_bottom += 1;
                                    }
                                }

                                if(count_from_bottom == pre_count) flag = true;

                                if(flag){
                                    item.push_back(candidates[i]);
                                    res_tensor[j].push_back(item);
                                }
                            }

                        }
                    }
                    pre_count += 1;

                }
            }
            
            /*
            cout << "debug: " << endl;
            for(int i = 0; i <= target; ++i){
                cout << "target: " << i << endl;
                if(res_tensor[i].size() > 0){
                    for(auto item: res_tensor[i]){
                        for(auto subitem: item){
                            cout << subitem << " ";
                        }
                        cout << endl;
                    }
                }
            }*/

            return res_tensor[target];

        }
};

int main(){

    Solution s = Solution();

    vector<int> vec_a{10,1,2,7,6,1,5};
    int target_a = 8;
    auto res_a = s.combinationSum2(vec_a, target_a);
    cout << "res: " << endl;
    for(auto item: res_a){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> vec_b{2,5,2,1,2};
    int target_b = 1;
    auto res_b = s.combinationSum2(vec_b, target_b);
    cout << "res: " << endl;
    for(auto item: res_b){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}