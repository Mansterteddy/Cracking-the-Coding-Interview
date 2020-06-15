#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {

        int mod = pow(10, 9) + 7;

        if(3 > A.size()) return 0;

        vector<vector<int> > pre_vector(4, vector<int>(target+1, 0));
        vector<vector<int> > cur_vector(4, vector<int>(target+1, 0));

        pre_vector[0][0] = 1;
        pre_vector[1][A[0]] = 1;

        for(int i = 1; i < A.size(); ++i){
            
            for(int j = 0; j <= 3; ++j){
                
                for(int k = 0; k <= target; ++k){
                    
                    if(k >= A[i] && j >= 1){
                        cur_vector[j][k] = pre_vector[j][k] + pre_vector[j-1][k-A[i]];
                        cur_vector[j][k] = cur_vector[j][k] % mod;
                    }
                    else{
                        cur_vector[j][k] = pre_vector[j][k];
                        cur_vector[j][k] = pre_vector[j][k] % mod;
                    }

                }
            }
            pre_vector = cur_vector;
            vector<vector<int> > temp(4, vector<int>(target+1, 0));
            cur_vector = temp;
        }

        return pre_vector[3][target];
    }
};

int main(){

    Solution s = Solution();

    int Arr_A[] = {1,1,2,2,3,3,4,4,5,5};
    vector<int> A(Arr_A, Arr_A + 10);
    int target = 8;
    int res = s.threeSumMulti(A, target);
    cout << res << endl;

    int Arr_B[] = {1,1,2,2,2,2};
    vector<int> B(Arr_B, Arr_B + 6);
    target = 5;
    res = s.threeSumMulti(B, target);
    cout << res << endl;

    return 0;
}