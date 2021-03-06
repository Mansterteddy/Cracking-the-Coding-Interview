#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
    public:
        void nextPermutation(vector<int>& nums){
            if(nums.size() <= 1) return;

            bool is_max = true;
            int key_pos = -1;
            for(int i = nums.size() - 2; i >= 0; i--){
                if(nums[i] < nums[i+1]){
                    key_pos = i;
                    is_max = false;
                    break;
                }
            }

            //cout << "key_pos: " << key_pos << endl;

            if(is_max){
                sort(nums.begin(), nums.end());
                return;
            }

            int nearest_pos = key_pos + 1;
            int nearest_val = nums[key_pos+1];
            for(int i = key_pos+2; i < nums.size(); ++i){
                if(nums[i] > nums[key_pos] && nums[i] < nearest_val){
                    nearest_val = nums[i];
                    nearest_pos = i;
                }
            }

            //cout << nearest_pos << " " << nearest_val << endl;

            swap(nums[nearest_pos], nums[key_pos]);
            sort(nums.begin()+key_pos+1, nums.end());

            return;

        }
};

int main(){

    Solution s = Solution();

    vector<int> test{2, 0, 5, 2, 1};
    s.nextPermutation(test);
    for(auto item: test){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_a{1, 2, 3};
    s.nextPermutation(test_a);
    for(auto item: test_a){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_b{3, 2, 1};
    s.nextPermutation(test_b);
    for(auto item: test_b){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_c{1, 1, 5};
    s.nextPermutation(test_c);
    for(auto item: test_c){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_d{1};
    s.nextPermutation(test_d);
    for(auto item: test_d){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}