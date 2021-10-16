#include <vector>
#include <iostream>

using namespace std;

// C(n, m) = n! / m! * (n-m)!, C(n, m-1) = n! / (m-1)! * (n - m + 1)!, C(n, m) = C(n, m-1) * (n - m + 1) / m
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        if(rowIndex == 0){
            vector<int> res{1};
            return res;
        }

        if(rowIndex == 1){
            vector<int> res{1, 1};
            return res;
        }

        vector<int> res(rowIndex+1, 0);

        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i){
            res[i] = 1LL * res[i-1] * (rowIndex - i + 1) / i;
        }

        return res;
    }
};

int main(){

    Solution s = Solution();

    auto res = s.getRow(3);
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;

    res = s.getRow(0);
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;

    res = s.getRow(1);
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}