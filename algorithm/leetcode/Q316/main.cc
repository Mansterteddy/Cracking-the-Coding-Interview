#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string removeDuplicateLetters(string s){

        }
};

int main(){

    Solution s = Solution();

    string str = "bcabc";
    string res = s.removeDuplicateLetters(str);
    cout << res << endl;

    str = "cbacdcbc";
    res = s.removeDuplicateLetters(str);    
    cout << res << endl;

    return 0;
}