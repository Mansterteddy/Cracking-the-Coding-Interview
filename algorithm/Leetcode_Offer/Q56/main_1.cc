#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> singleNumbers(vector<int>& nums){
            int ret = 0;
            for(int i = 0; i < nums.size(); ++i){
                ret ^= nums[i];
            }

            //cout << ret << endl;

            int div = 1;
            while(true){
                if(ret & div){
                    break;
                }
                else{
                    div *= 2;
                }
            }

            //cout << div << endl;

            int a = 0;
            int b = 0;

            for(int i = 0; i < nums.size(); ++i){
                
                if(nums[i] & div){
                    a ^= nums[i];
                }
                else{
                    b ^= nums[i];
                }
            }

            vector<int> res{a, b};
            return res;

        }
};

int main(){

    Solution s = Solution();

    vector<int> nums_1{4, 1, 4, 6};
    vector<int> res_1 = s.singleNumbers(nums_1);
    for(int i = 0; i < res_1.size(); ++i){
        cout << res_1[i] << " ";
    }
    cout << endl;
    
    vector<int> nums_2{1, 2, 10, 4, 1, 4, 3, 3};
    vector<int> res_2 = s.singleNumbers(nums_2);
    for(int i = 0; i < res_2.size(); ++i){
        cout << res_2[i] << " ";
    }
    cout << endl;

    return 0;
}