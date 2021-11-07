#include <iostream>

using namespace std;

class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


int main(){

    Solution s = Solution();

    bool res_1 = s.isPalindrome("A man, a plan, a canal: Panama");
    cout << res_1 << endl;

    bool res_2 = s.isPalindrome("race a car");
    cout << res_2 << endl;

    return 0;
}