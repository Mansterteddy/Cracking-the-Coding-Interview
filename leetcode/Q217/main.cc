#include <map>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};


class Solution1 {
    public:
        bool containsDuplicate(vector<int>& nums){
            
            bool flag = false;
            
            if(nums.size() == 0 || nums.size() == 1){
                return flag;
            }
            
            map<int, bool> hash_map;

            for(int i = 0; i < nums.size(); ++i){
                map<int, bool>::iterator map_iter = hash_map.find(nums[i]);

                if(map_iter == hash_map.end()){
                    hash_map[nums[i]] = true;
                }
                else{
                    flag = true;
                    break;
                }

            }

            return flag;

        }
};

int main(){

    Solution s = Solution();

    vector<int> a{1, 2, 3, 1};
    bool res = s.containsDuplicate(a);
    cout << res << endl;

    vector<int> b{1, 2, 3, 4};
    res = s.containsDuplicate(b);
    cout << res << endl;

    vector<int> c{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    res = s.containsDuplicate(c);
    cout << res << endl;

    return 0;
}