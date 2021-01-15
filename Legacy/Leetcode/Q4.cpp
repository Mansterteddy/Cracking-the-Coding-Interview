//There are two sorted arrays nums1 and nums2 of size m and n respectively.

//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//这道题的本质是考察在两个有序数组中寻找第k个元素，用到的是递归
//记得处理多种情况，当一个数组无元素时，那么就是在另一个数组中寻找第k个元素
//如果index=1，就到了边界情况，寻找两个数组头元素，较小的那一个
//两个数组的大小是有顺序的，把小的数组放在前面，方便处理
//对比两个元素的第index / 2元素，要记着，有时候index是会大于小数组大小的一半的，要考虑这种情况，随后不断递归
//这个方法最好使用数组，而非vector
class Solution {
    public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        int* num1 = new int[nums1.size()];
        for(int i = 0; i < nums1.size(); i++)
        {   
            num1[i] = nums1[i];
        }

        int* num2 = new int[nums2.size()];
        for(int i = 0; i < nums2.size(); i++)
        {   
            num2[i] = nums2[i];
        }

        if(total & 0x1)
        {
            return find_kth(num1, nums1.size(), num2, nums2.size(), total / 2 + 1);
        }
        else
        {
            return (find_kth(num1, nums1.size(), num2, nums2.size(), total / 2) + find_kth(num1, nums1.size(), num2, nums2.size(), total / 2 + 1)) / 2.0;
        }
        
    }
    private:
        int find_kth(int* num1, int m, int* num2, int n, int index)
        {
            if(m == 0) return num2[index - 1];
            if(n == 0) return num1[index - 1];
            if(index == 1) return min(num1[0], num2[0]);
            if(m > n) return find_kth(num2, n, num1, m, index);

            int ia = min(index / 2, m);
            int ib = index - ia;

            if(num1[ia - 1] < num2[ib - 1])
            {
                return find_kth(num1 + ia, m - ia, num2, n, index - ia);
            }
            else if(num1[ia - 1] > num2[ib - 1])
            {
                return find_kth(num1, m, num2 + ib, n - ib, index - ib);
            }
            else
            {
                return num1[ia - 1];
            }
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