//There are two sorted arrays nums1 and nums2 of size m and n respectively.

//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        if(total & 0x1)
        {
            return find_kth(nums1, nums2, total / 2 + 1);
        }
        else
        {
            return (find_kth(nums1, nums2, total / 2) + find_kth(nums1, nums2, total / 2 + 1)) / 2;
        }
        
    }
    private:
        int find_kth(vector<int>& nums1, vector<int>& nums2, int index)
        {

        }
};

int main()
{
    vector<int> num1 = {1, 2, 3, 4};
    vector<int> num2 = {5, 6, 7, 8};

    Solution s1;
    double res = s1.findMedianSortedArrays(num1, num2);
    cout<<"Ans is "<<res<<endl;

    num1 = {0};
    num2 = {6, 7, 8, 9};
    res = s1.findMedianSortedArrays(num1, num2);
    cout<<"Ans is "<<res<<endl;
    
    return 0;
}