#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val){
            
            int start_index = 0;
            int end_index = nums.size() - 1;

            while(start_index <= end_index){
                if(nums[start_index] == val){
                    swap(nums[start_index], nums[end_index]);
                    end_index -= 1;
                }
                else{
                    start_index += 1;
                }
            }
            
            return end_index + 1;

        }
};

int main(){

    Solution s = Solution();

    vector<int> a{3, 2, 2, 3};
    int res_a = s.removeElement(a, 3);
    cout << res_a << endl;

    vector<int> b{0, 1, 2, 2, 3, 0, 4, 2};
    int res_b = s.removeElement(b, 2);
    cout << res_b << endl;

    return 0;
}