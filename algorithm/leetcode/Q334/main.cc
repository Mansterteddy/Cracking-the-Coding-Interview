#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int small = INT_MAX;
        int mid = INT_MAX;
        for(auto num: nums){
            if(num <= small) small = num;
            else if(num <= mid) mid = num;
            else return true;
        }
        return false;
    }
};

int main(){
    Solution s = Solution();

    vector<int> a{1, 2, 3, 4, 5};
    cout << s.increasingTriplet(a) << endl;

    vector<int> b{5, 4, 3, 2, 1};
    cout << s.increasingTriplet(b) << endl;

    vector<int> c{2, 1, 5, 0, 4, 6};
    cout << s.increasingTriplet(c) << endl;

    return 0;
}