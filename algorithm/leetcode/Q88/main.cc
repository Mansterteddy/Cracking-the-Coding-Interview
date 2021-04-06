#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
            int nums1_index = m - 1;
            int nums2_index = n - 1;

            int start_index = m + n - 1;
            while(nums1_index >= 0 && nums2_index >= 0){
                if(nums1[nums1_index] >= nums2[nums2_index]){
                    nums1[start_index] = nums1[nums1_index];
                    nums1_index -= 1;
                }
                else{
                    nums1[start_index] = nums2[nums2_index];
                    nums2_index -= 1;
                }

                start_index -= 1;
            }

            if(nums1_index >= 0){
                while(nums1_index >= 0){
                    nums1[start_index] = nums1[nums1_index];
                    start_index -= 1;
                    nums1_index -= 1;
                }
            }

            if(nums2_index >= 0){
                while(nums2_index >= 0){
                    nums1[start_index] = nums2[nums2_index];
                    start_index -= 1;
                    nums2_index -= 1;
                }
            }
        }
};

int main(){

    Solution s = Solution();

    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2{2, 5, 6};
    int n = 3;

    s.merge(nums1, 3, nums2, 3);

    for(auto item: nums1){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}