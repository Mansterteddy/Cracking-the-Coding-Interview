#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits){
            
            vector<int> res = digits;

            int next_pos = 0;

            for(int i = res.size() - 1; i >= 0; --i){

                if(res[i] == 9){
                    res[i] = 0;
                    next_pos = 1;
                }
                else{
                    res[i] += 1;
                    next_pos = 0;
                    break;
                }
            }

            if(next_pos == 1){
                res.insert(res.begin(), 1);
            }

            return res;

        }
};

int main(){

    Solution s = Solution();

    //vector<int> digits{1, 2, 3};
    //vector<int> digits{9, 9};
    vector<int> digits{1, 9, 9};

    vector<int> res = s.plusOne(digits);

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }

    return 0;

}