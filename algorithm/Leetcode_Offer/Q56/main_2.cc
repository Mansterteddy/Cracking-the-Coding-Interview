#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

        void countNumber(int num, vector<int>& mem){

            int i = 0;
            while(num != 0){
                int cur_val = num % 2;
                if(cur_val == 1){
                    mem[i] += 1;
                }
                num /= 2;
                i += 1;
            }

        }

        int singleNumber(vector<int>& nums){

            vector<int> mem(32, 0);
            cout << mem.size() << endl;

            for(int i = 0; i < nums.size(); ++i){
                countNumber(nums[i], mem);
            }

            // for(int i = 0; i < mem.size(); ++i){
            //     cout << mem[i] << " ";
            // }
            // cout << endl;

            int res = 0;
            for(int i = 0; i < mem.size(); ++i){
                if(mem[i] % 3 != 0)
                    res += pow(2, i);
            }

            return res;

        }
};

int main(){

    Solution s = Solution();

    vector<int> nums{3, 4, 3, 3};
    int res = s.singleNumber(nums);
    cout << res << endl;

    vector<int> nums_2{9, 1, 7, 9, 7, 9, 7};
    int res_2 = s.singleNumber(nums_2);
    cout << res_2 << endl;

    return 0;
}