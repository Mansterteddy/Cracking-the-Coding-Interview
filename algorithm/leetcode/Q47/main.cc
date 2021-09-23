#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    void recursivePermute(vector<int>& res_item, vector<vector<int>>& res, vector<int>& visit, vector<int>& nums){
        if(res_item.size() == nums.size()){
            res.push_back(res_item);
        }

        for(int i = 0; i < nums.size(); ++i){
            if(visit[i] != 0) continue;

            if(i > 0 && nums[i] == nums[i-1] && visit[i-1] == 0) continue;

            res_item.push_back(nums[i]);
            visit[i] = 1;
            recursivePermute(res_item, res, visit, nums);
            visit[i] = 0;
            res_item.pop_back();
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> visit; 
        for(int i = 0; i < nums.size(); ++i){
            visit.push_back(0);
        }

        vector<int> res_item;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        recursivePermute(res_item, res, visit, nums);

        return res;
    }
};

int main(){

    Solution s = Solution();

    vector<int> nums_1{1, 1, 2};
    auto res_1 = s.permuteUnique(nums_1);
    for(auto item: res_1){
        for(auto int_item: item){
            cout << int_item << " ";
        }
        cout << endl;
    }    

    vector<int> nums_2{1, 2, 3};
    auto res_2 = s.permuteUnique(nums_2);
    for(auto item: res_2){
        for(auto int_item: item){
            cout << int_item << " ";
        }
        cout << endl;
    }    

    vector<int> nums_3{3, 3, 0, 3};
    auto res_3 = s.permuteUnique(nums_3);
    for(auto item: res_3){
        for(auto int_item: item){
            cout << int_item << " ";
        }
        cout << endl;
    }   

    return 0;
}