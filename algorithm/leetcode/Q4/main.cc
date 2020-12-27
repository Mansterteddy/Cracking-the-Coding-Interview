#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.size() == 0){
                if(nums2.size() % 2 == 0){
                    return 
                }
                else{
                    
                }
            }
            if(nums2.size() == 0){
                return 
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