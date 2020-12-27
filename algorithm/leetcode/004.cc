#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:

        double getMid(vector<int>& nums, int start, int length){            
            
            if (length % 2 == 0){
                return double(nums[start + int(length / 2) - 1] + nums[start + int(length / 2)]) / 2.0;
            }
            else{
                return nums[start + int(length / 2)];
            }   

        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            int len_1 = nums1.size();
            int len_2 = nums2.size();

            if (len_1 == 0){
                return getMid(nums2, 0, len_2);
            }

            if (len_2 == 0){
                return getMid(nums1, 0, len_1);
            }

            

        }
};

int main(){
    cout << "LeetCode 004" << endl;

    Solution so = Solution();

    int array_1[] = {1, 2, 3, 4, 5};
    vector<int> num1(array_1, array_1 + 5);

    int array_2[] = {4, 5, 6};
    vector<int> num2(array_2, array_2 + 3);

    double res = so.findMedianSortedArrays(num1, num2);
    cout << "Res: " << res << endl;

    return 0;
}