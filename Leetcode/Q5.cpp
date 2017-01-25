//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

/*
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Input: "cbbd"

Output: "bb"
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int *arr = new int[s.length()];
        for(int i = 0; i < s.length(); ++i)
        {
            if(i = 0) arr[i] = 1;
            else
            {
                
            }
        }
    }
};

int main()
{
    Solution s1;

    string s = "babad";
    string ans = s1.longestPalindrome(s);
    cout<<"Ans is: "<<ans<<endl;

    s = "cbbd";
    ans = s1.longestPalindrome(s);
    cout<<"Ans is: "<<ans<<endl;

    return 0;
}