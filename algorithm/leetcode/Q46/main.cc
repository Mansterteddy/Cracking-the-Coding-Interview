#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

        vector<vector<int>> permute(vector<int>& nums, int index){
            
            if(index == nums.size() - 1){
                vector<int> res_item{nums[index]};
                vector<vector<int>> res{res_item};
                return res;
            }
            else{
                vector<vector<int>> res;
                for(int i = index; i < nums.size(); ++i){
                    swap(nums[index], nums[i]);
                    vector<vector<int>> temp_res = permute(nums, index + 1);
                    for(int j = 0; j < temp_res.size(); ++j){
                        vector<int> temp_res_item{nums[index]};
                        for(int k = 0; k < temp_res[j].size(); ++k){
                            temp_res_item.push_back(temp_res[j][k]);
                        }
                        res.push_back(temp_res_item);
                    }
                    swap(nums[i], nums[index]);
                }
                return res;
            }
        }

        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>> res = permute(nums, 0);
            return res;
        }
};

int main(){

    Solution s = Solution();

    vector<int> a{1, 2, 3, 4};

    vector<vector<int>> res = s.permute(a);

    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}