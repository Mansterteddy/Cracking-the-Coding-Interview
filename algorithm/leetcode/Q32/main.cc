#include <iostream>

using namespace std;


class Solution {
public:

    int lengthOfValidParenthesesGiveStart(string s, int start){
        
        int count = 0;
        int max_count = 0;
        for(int i = start; i < s.size(); i++){
            if(s[i] == '(')
                count++;
            else if(s[i] == ')')
                count--;
            if(count == 0){
                max_count = max(max_count, i - start + 1);
            }
            if(count < 0)
                return i - start;
        }

        return max_count;
    }


    int longestValidParentheses(string s) {
        if(s == "") return 0;

        int maxLen = 0;

        for(int i = 0; i < s.length(); ++i){

            if(s[i] == '('){
                int len = lengthOfValidParenthesesGiveStart(s, i);

                if(len > maxLen)
                    maxLen = len;

                if(len == s.size() - i)
                    break;
            }

        }

        return maxLen;

    }
};

int main(){

    Solution s = Solution();

    int res_1 = s.longestValidParentheses("(()");
    cout << res_1 << endl;

    int res_2 = s.longestValidParentheses(")()())");
    cout << res_2 << endl;

    int res_3 = s.longestValidParentheses("");
    cout << res_3 << endl;

    int res_4 = s.longestValidParentheses("(())(");
    cout << res_4 << endl;

    return 0;
}