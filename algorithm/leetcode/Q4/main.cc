#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:

        double findNthSortedArrays(vector<int>& nums1, int start_1, int len_1, vector<int>& nums2, int start_2, int len_2, int n){
            
            if(len_1 > len_2){
                return findNthSortedArrays(nums2, start_2, len_2, nums1, start_1, len_1, n);
            }

            //cout << start_1 << " " << len_1 << " " << start_2 << " " << len_2 << " "<< n << endl;
            
            if(len_1 == 0) return nums2[start_2 + n];

            if(n == 0) return min(nums1[start_1], nums2[start_2]);

            int index_1 = min(n / 2, len_1 - 1);
            int index_2 = n - index_1 - 1;

            //cout << "index: " << index_1 << " " << index_2 << " " << nums1[start_1 + index_1] << " " << nums2[start_2 + index_2] << endl;

            if(nums1[start_1 + index_1] < nums2[start_2 + index_2])
                return findNthSortedArrays(nums1, start_1 + index_1 + 1, len_1 - index_1 - 1, nums2, start_2, len_2, n - index_1 - 1);
            else if(nums1[start_1 + index_1] > nums2[start_2 + index_2])
                return findNthSortedArrays(nums1, start_1, len_1, nums2, start_2 + index_2 + 1, len_2 - index_2 - 1, n - index_2 - 1);
            else{
                return nums1[start_1 + index_1];
            }
        }

        // a1 a2 a3
        // b1 b2 b3 b4 b5
        // a2 > b3

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

            int nums1_size = nums1.size();
            int nums2_size = nums2.size();
            int all_num = nums1_size + nums2_size;

            if(nums1_size < nums2_size){
                if(all_num % 2 == 1)
                    return findNthSortedArrays(nums1, 0, nums1_size, nums2, 0, nums2_size, all_num / 2);
                else
                    return (findNthSortedArrays(nums1, 0, nums1_size, nums2, 0, nums2_size, all_num / 2 - 1) + findNthSortedArrays(nums1, 0, nums1_size, nums2, 0, nums2_size, all_num / 2)) / 2;
            }
            else{
                if(all_num % 2 == 1)
                    return findNthSortedArrays(nums2, 0, nums2_size, nums1, 0, nums1_size, all_num / 2);
                else
                    return (findNthSortedArrays(nums2, 0, nums2_size, nums1, 0, nums1_size, all_num / 2 - 1) + findNthSortedArrays(nums2, 0, nums2_size, nums1, 0, nums1_size, all_num / 2)) / 2;
            }
        }
};

int main(){

    cout << "LeetCode 004" << endl;

    Solution s = Solution();

    //vector<int> num1{1, 3};
    //vector<int> num2{2};

    // vector<int> num1{1, 3};
    // vector<int> num2{2, 4};
    
    //vector<int> num1{};
    //vector<int> num2{1, 2, 3};

    vector<int> num1{3, 4, 5};
    vector<int> num2{1, 2, 3, 4, 5};

    double res = s.findMedianSortedArrays(num1, num2);
    cout << "Res: " << res << endl;

    return 0;
}