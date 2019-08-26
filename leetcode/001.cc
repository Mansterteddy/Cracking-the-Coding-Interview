#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            map<int, int> nums_map;

            for(int i = 0; i < nums.size(); ++i){
                int cur_val = nums[i];
                int expected_val = target - cur_val;
                map<int, int>::iterator iter = nums_map.find(expected_val);  
                if(iter != nums_map.end()){
                    res.push_back(nums_map[expected_val]);
                    res.push_back(i);
                    return res;
                }
                else{
                    nums_map[cur_val] = i;
                }
            }

            return res;
    }
};

int main(){
    cout << "Hello, World!" << endl;
    int a[] = {2, 7, 11, 15};
    vector<int> nums(a, a+4);
    int target = 26;

    Solution so = Solution();

    vector<int> res = so.twoSum(nums, target);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }

    return 0;
}