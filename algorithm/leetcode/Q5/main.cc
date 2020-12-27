#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {



    }
};


int main(){

    Solution s = Solution();

    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << res << endl;

    str = "cbbd";
    res = s.longestPalindrome(str);
    cout << res << endl;

    return 0;
}