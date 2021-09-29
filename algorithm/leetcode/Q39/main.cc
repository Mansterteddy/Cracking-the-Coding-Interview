#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:

        void addToVec(vector<vector<vector<int>>>& res_vec, int last_pos, int cur_pos, int cur_val){

                //cout << "debug: " << last_pos << " " << cur_pos << " " << cur_val;

                auto prev_list = res_vec[last_pos];
                //cout << " prev_list size: " << prev_list.size() << endl;

                for(int i = 0; i < prev_list.size(); ++i){
                    auto cur_vec = prev_list[i];
                    cur_vec.push_back(cur_val);
                    res_vec[cur_pos].push_back(cur_vec);
                }

        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target){
            vector<vector<int>> init_vec;
            vector<vector<vector<int>>> res_vec(target+1, init_vec);
            vector<int> prev_vec(target+1, 0);
            vector<int> curr_vec(target+1, 0);

            if(candidates.size() == 1){
                if(candidates[0] > target){
                    return init_vec;
                }
                else{
                    if(target % candidates[0] == 0){
                        int count = target / candidates[0];
                        vector<int> temp_res;
                        for(int i = 0; i < count; ++i){
                            temp_res.push_back(candidates[0]);
                        }
                        init_vec.push_back(temp_res);
                        return init_vec;
                    }
                    else{
                        return init_vec;
                    }
                }
            }

            vector<int> first_vec;
            res_vec[0].push_back(first_vec);
            if(candidates[0] <= target){
                int cur_val = candidates[0];
                int count = 1;
                while(cur_val <= target){
                    prev_vec[cur_val] = 1;
                    vector<int> temp_vec;
                    for(int i = 0; i < count; ++i)
                        temp_vec.push_back(candidates[0]);
                    res_vec[cur_val].push_back(temp_vec);
                    count += 1;
                    cur_val += candidates[0];
                }
            }

            for(int i = 1; i < candidates.size(); ++i){
                if(candidates[i] > target){
                    continue;
                }
                else if(candidates[i] == target){
                    curr_vec[target] += 1;
                    vector<int> temp_vec(1, target);
                    res_vec[target].push_back(temp_vec);
                    prev_vec = curr_vec;
                }
                else{                    
                    for(int j = 0; j <= target; ++j){
                        if(j == 0 || j < candidates[i]){
                            curr_vec[j] = prev_vec[j];
                            continue;
                        }
                        if(j >= candidates[i]){
                            curr_vec[j] = prev_vec[j] + prev_vec[j-candidates[i]] + curr_vec[j-candidates[i]];
                            addToVec(res_vec, j-candidates[i], j, candidates[i]);
                        }
                    }
                    prev_vec = curr_vec;
                }
            }

            return res_vec[target];
        }
};

int main(){

    Solution s = Solution();

    vector<int> vec_a{2, 3, 6, 7};
    int target_a = 7;
    auto res_a = s.combinationSum(vec_a, target_a);
    for(auto item: res_a){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> vec_b{2, 3, 5};
    int target_b = 8;
    auto res_b = s.combinationSum(vec_b, target_b);
    for(auto item: res_b){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> vec_c{2};
    int target_c = 1;
    auto res_c = s.combinationSum(vec_c, target_c);
    for(auto item: res_c){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> vec_d{1};
    int target_d = 1;
    auto res_d = s.combinationSum(vec_d, target_d);
    for(auto item: res_d){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> vec_e{1};
    int target_e = 2;
    auto res_e = s.combinationSum(vec_e, target_e);
    for(auto item: res_e){
        for(auto sub_item: item){
            cout << sub_item << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}