#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x){

            double old_x = x;

            if(x < 0) return false;

            double new_x = 0;
            while(x != 0){
                new_x *= 10;
                new_x += x % 10;
                x = x / 10;
            }

            if (old_x == new_x)
                return true;
            else
                return false;
        }
};

class Solution1 {
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

    Solution s = Solution();

    int a = 1234567899;
    bool res = s.isPalindrome(a);
    cout << res << endl;

    return 0;
}

