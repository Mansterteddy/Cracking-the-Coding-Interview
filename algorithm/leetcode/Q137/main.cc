#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

        void countNumber(long long num, vector<int>& mem){
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
            int larger_zero_count = 0;
            int smaller_zero_count = 0;
            //cout << mem.size() << endl;

            for(int i = 0; i < nums.size(); ++i){
                
                long long temp_val = nums[i];
                countNumber(abs(temp_val), mem);
                if(nums[i] > 0){
                    larger_zero_count += 1;
                }
                else{
                    smaller_zero_count += 1;
                }
            }

            // for(int i = 0; i < mem.size(); ++i){
            //     cout << mem[i] << " ";
            // }
            // cout << endl;

            long long res = 0;
            for(int i = 0; i < mem.size(); ++i){
                if(mem[i] % 3 != 0)
                    res += pow(2, i);
            }

            if(larger_zero_count % 3 == 0){
                res = -res;
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    vector<int> nums_1{2, 2, 3, 2};
    int res_1 = s.singleNumber(nums_1);
    cout << res_1 << endl;

    vector<int> nums_2{0, 1, 0, 1, 0, 1, 99};
    int res_2 = s.singleNumber(nums_2);
    cout << res_2 << endl;

    vector<int> nums_3{-2,-2,1,1,4,1,4,4,-4,-2};
    int res_3 = s.singleNumber(nums_3);
    cout << res_3 << endl;

    return 0;
}