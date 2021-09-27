#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

    int findLeftTarget(vector<int>& nums, int target, int cur_pos){
        
        if(cur_pos == 0) return 0;
        if(nums[0] == target) return 0;        
        int res = cur_pos;
        if(nums[cur_pos-1] != target) return res;

        int left_pos = 0;
        int right_pos = cur_pos - 1;
        int mid_pos = (left_pos + right_pos) / 2;

        while(left_pos <= right_pos){
            //cout << "left_pos: " << left_pos << " right_pos: " << right_pos << endl;
            if(nums[mid_pos] == target){
                if(nums[mid_pos-1] != target) return mid_pos;
                right_pos = mid_pos - 1;
            }
            else if(nums[mid_pos] < target){
                if(nums[mid_pos+1] == target) return mid_pos + 1;
                left_pos = mid_pos + 1;
            }
            mid_pos = (left_pos + right_pos) / 2;
        }

        return res;
    }

    int findRightTarget(vector<int>& nums, int target, int cur_pos){

        if(cur_pos == nums.size()-1) return nums.size()-1;      
        if(nums[nums.size()-1] == target) return nums.size()-1;  
        int res = cur_pos;
        if(nums[cur_pos+1] != target) return res;

        int left_pos = cur_pos + 1;
        int right_pos = nums.size() - 1;
        int mid_pos = (left_pos + right_pos) / 2;

        while(left_pos <= right_pos){
            if(nums[mid_pos] == target){
                if(nums[mid_pos+1] != target) return mid_pos;
                left_pos = mid_pos + 1;
            }
            else if(nums[mid_pos] > target){
                if(nums[mid_pos-1] == target) return mid_pos - 1;
                right_pos = mid_pos - 1;
            }
            mid_pos = (left_pos + right_pos) / 2;
        }

        return res;
    }

    int findTarget(vector<int>& nums, int target){
        int res = -1;

        if(target < nums[0] || target > *(nums.end()-1)) return res;
        
        if(target == nums[0]) return 0;
        if(target == *(nums.end()-1)) return (nums.size()-1);

        int left_pos = 0;
        int right_pos = nums.size()-1;
        int mid_pos = (left_pos + right_pos) / 2;

        while(left_pos <= right_pos){
            if(nums[left_pos] == target) return left_pos;
            if(nums[right_pos] == target) return right_pos;            
            if(nums[mid_pos] == target) return mid_pos;
            
            if(target < nums[mid_pos]){
                right_pos = mid_pos - 1;
                mid_pos = (left_pos + right_pos) / 2;
            }
            else{
                left_pos = mid_pos + 1;
                mid_pos = (left_pos + right_pos) / 2;
            }
        }

        return res;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if(nums.size() == 0) return res;
        if(nums.size() == 1)
        {
            if(nums[0] != target){
                return res;
            }
            else{
                res[0] = 0;
                res[1] = 0;
                return res;
            }
        }

        int target_pos = findTarget(nums, target);
        //cout << "target pos: " << target_pos << endl;

        if(target_pos == -1) return res;

        int left_pos = findLeftTarget(nums, target, target_pos);
        //cout << "left pos: " << left_pos << endl;
        int right_pos = findRightTarget(nums, target, target_pos);
        //cout << "right pos: " << right_pos << endl;
        res[0] = left_pos;
        res[1] = right_pos;

        return res;

    }   
};

int main(){

    Solution s = Solution();

    vector<int> test_1{5, 7, 7, 8, 8, 10};
    auto res_1 = s.searchRange(test_1, 8);
    for(auto item: res_1){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_2{5, 7, 7, 8, 8, 10};
    auto res_2 = s.searchRange(test_1, 6);
    for(auto item: res_2){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_3{};
    auto res_3 = s.searchRange(test_3, 0);
    for(auto item: res_3){
        cout << item << " ";
    }
    cout << endl;

    vector<int> test_4{1,2,2,3,4,4,4};
    auto res_4 = s.searchRange(test_4, 4);
    for(auto item: res_4){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}