#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr){

            vector<vector<int>> res;

            if(arr.size() == 0 || arr.size() == 1){
                return res;
            }

            sort(arr.begin(), arr.end());

            int min_val = abs(arr[1] - arr[0]);

            for(int i = 1; i < arr.size(); ++i){
                int cur_diff = abs(arr[i] - arr[i-1]);
                if(cur_diff < min_val){
                    min_val = cur_diff;
                }
            }

            for(int i = 1; i < arr.size(); ++i){
                int cur_diff = abs(arr[i] - arr[i-1]);
                if(cur_diff == min_val){
                    vector<int> temp_res{arr[i-1], arr[i]};
                    res.push_back(temp_res);
                }
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    vector<int> arr_1{4, 2, 1, 3};
    vector<vector<int>> res_1 = s.minimumAbsDifference(arr_1);
    for(auto i : res_1){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> arr_2{1, 3, 6, 10, 15};
    vector<vector<int>> res_2 = s.minimumAbsDifference(arr_2);
    for(auto i : res_2){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> arr_3{3, 8, -10, 23, 19, -4, -14, 27};
    vector<vector<int>> res_3 = s.minimumAbsDifference(arr_3);
    for(auto i : res_3){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}