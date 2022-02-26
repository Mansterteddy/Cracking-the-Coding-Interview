#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int trap(vector<int>& height){
            if(height.size() <= 2) return 0;

            int left_val = height[0];
            int right_val = height[height.size() - 1];

            vector<int> left_vec;
            vector<int> right_vec;

            for(int i = 1; i < height.size() - 1; i++){
                if(height[i] < left_val){
                    left_vec.push_back(left_val);
                }
                else{
                    left_val = height[i];
                    left_vec.push_back(-1);
                }
            }

            for(int i = height.size() - 2; i > 0; --i){
                if(height[i] < right_val){
                    right_vec.push_back(right_val);
                }
                else{
                    right_val = height[i];
                    right_vec.push_back(-1);
                }
            }

            reverse(right_vec.begin(), right_vec.end());

            int res = 0;
            for(int i = 0; i < left_vec.size(); ++i){
                //cout << i << " " << left_vec[i] << " " << right_vec[i] << endl;
                if(left_vec[i] == -1 || right_vec[i] == -1) continue;
                res += min(left_vec[i], right_vec[i]) - height[i+1];
            }

            return res;

        }
};

int main(){

    Solution s = Solution();

    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(a) << endl;

    vector<int> b{4, 2, 0, 3, 2, 5};
    cout << s.trap(b) << endl;

    return 0;
}