#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(i==0)
                res.push_back(0);
            else
                res.push_back(-1);
        }

        for(int i = 0; i < nums.size(); ++i){

            for(int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j){
                if(res[j] == -1)
                    res[j] = res[i] + 1;

                if(j == nums.size() - 1)
                    return res[j];
            }
        }
        return res[nums.size()-1];
    }
};

int main(){

    Solution s = Solution();

    vector<int> nums{2, 3, 1, 1, 4};
    int res = s.jump(nums);
    cout << res << endl;

    return 0;
}