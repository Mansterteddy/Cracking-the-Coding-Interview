#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    public:

        int recursiveSearch(vector<int>& nums, int left, int right, int target)
        {
            if(nums[left] == target)
                return left;
            if(nums[right] == target)
                return right;

            if(left > right)
                return -1;

            if(right - left == 1)
                return -1;

            if(target > nums[right] && target < nums[left])
            {
                return -1;
            }

            int mid = (left + right) / 2;

            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > nums[left]){
                if(target < nums[mid]){
                    if(target >= nums[left])
                        return recursiveSearch(nums, left + 1, mid - 1, target);
                    else
                        return recursiveSearch(nums, mid + 1, right - 1, target);
                }
                else
                    return recursiveSearch(nums, mid + 1, right - 1, target);
            }
            else{
                if(target < nums[mid])
                {
                    return recursiveSearch(nums, left + 1, mid - 1, target);
                }
                else{
                    if(target > nums[left])
                        return recursiveSearch(nums, left + 1, mid - 1, target);
                    else
                        return recursiveSearch(nums, mid + 1, right - 1, target);
                }

            }

        }

        int search(vector<int>& nums, int target)
        {
            if(nums.size() == 0)
                return -1;
            if(nums.size() == 1){
                if(nums[0] == target)
                    return 0;
                else
                    return -1;
            }

            return recursiveSearch(nums, 0, nums.size() - 1, target);
        }
};

int main(){
    
    Solution s = Solution();

    vector<int> vec_1{4, 5, 6, 7, 0, 1, 2};
    int res_1 = s.search(vec_1, 0);
    cout << res_1 << endl;

    vector<int> vec_2{4, 5, 6, 7, 0, 1, 2};
    int res_2 = s.search(vec_2, 3);
    cout << res_2 << endl;

    vector<int> vec_3{1};
    int res_3 = s.search(vec_3, 0);
    cout << res_3 << endl;

    vector<int> vec_4{4, 5, 6, 7, 8, 1, 2, 3};
    int res_4 = s.search(vec_4, 8);
    cout << res_4 << endl;

    return 0;
}