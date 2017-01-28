//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

/*
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Input: "cbbd"

Output: "bb"
*/
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //这样方法声明的二维数组是间断的
        /*
        连续二维数组声明
        int *array = new int[s.length() * s.length()];
        int **arr;
        arr = new int *[s.length()];
        for(int i = 0; i < s.length())
            arr[i] = array + i * s.elngth();
        */
        int flag = -1;
        int max = 0;

        int **arr = new int*[s.length()];
        for(int i = 0; i < s.length(); ++i)
        {
            //数组初始化就是在后面加个()
            arr[i] = new int[s.length()]();
        }

        for(int i = 0; i < s.length(); ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                if(j == 0) arr[i][j] = 1;
                else if(j == 1)
                {
                    if(s[i] == s[i-1]) arr[i][j] = 2;
                    else arr[i][j] = 0;
                }
                else if(j == 2)
                {
                    if(s[i] == s[i-2]) arr[i][j] = 3;
                    else arr[i][j] = 0;
                }
                else
                {
                    if(arr[i-1][j-2] != 0 && s[i] == s[i-arr[i-1][j-2] - 1]) arr[i][j] = j + 1;
                    else arr[i][j] = 0;
                }

                if(arr[i][j] >= max)
                {
                    flag = i;
                    max = arr[i][j];
                }
            }
        }

        /*for(int i = 0; i < s.length(); ++i)
        {
            for(int j = 0; j < s.length(); ++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/

        string ans = "";
        for(int i = 0; i < max; ++i)
        {
            ans = s[flag - i] + ans;
        }
        return ans;
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

    s = "bbabba";
    ans = s1.longestPalindrome(s);
    cout<<"Ans is: "<<ans<<endl;
    return 0;
}