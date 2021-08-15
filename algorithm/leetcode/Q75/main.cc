#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:

        void sortColors(vector<int>& nums){
            if(nums.size() == 1) return;

            int first_count = 0;
            int second_count = 0;
            int third_count = 0;

            for(auto x: nums){
                if(x == 0)
                    first_count += 1;
                else if(x == 1)
                    second_count += 1;
                else
                    third_count += 1;
            }

            for(int i = 0; i < nums.size(); ++i){
                if(i < first_count){
                    nums[i] = 0;
                }
                else if(i < first_count + second_count){
                    nums[i] = 1;
                }
                else{
                    nums[i] = 2;
                }
            }
        }
};

int main(){

    Solution s = Solution();

    vector<int> nums_1{2, 0, 2, 1, 1, 0};
    s.sortColors(nums_1);
    for(auto val: nums_1){
        cout << val << " ";
    }

    vector<int> nums_2{2, 0, 1};
    s.sortColors(nums_2);
    for(auto val: nums_2){
        cout << val << " ";
    }

    vector<int> nums_3{0};
    s.sortColors(nums_3);
    for(auto val: nums_3){
        cout << val << " ";
    }

    vector<int> nums_4{1};
    s.sortColors(nums_4);
    for(auto val: nums_4){
        cout << val << " ";
    }

    return 0;
}
