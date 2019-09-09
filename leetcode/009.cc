#include <iostream>

using namespace std;

class Solution {
    public: 
        bool isPalindrome(int x){

            if (x < 0){
                return false;
            }

            if (x >= 0 && x < 10){
                return true;
            }

            string a = to_string(x);
            int len_a = a.size();

            for(int i = 0; i < len_a; ++i){
                char start = a[i];
                char end = a[len_a - 1 - i];
                if(start != end){
                    return false;
                }
            }
            
            return true;
    }
};

int main(){

    cout << "LeetCode 009" << endl;

    //int a = 121;
    //int a = -121;
    int a = 10;

    Solution so = Solution();

    bool res = so.isPalindrome(a);
    cout << "res: " << res << endl;

    return 0;
}