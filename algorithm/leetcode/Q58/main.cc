#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s){

            int res = 0;
            int start = s.length() - 1;

            for(int i = s.length() - 1; i >= 0; --i){
                if(s[i] != ' '){
                    break;
                }
                else{
                    start -= 1;
                }
            }

            for(int i = start; i >= 0; --i){
                if(s[i] == ' '){
                    return res;
                }
                else{
                    res += 1;
                }

            }

            return res;

        }
};


int main(){

    Solution s = Solution();

    int res = s.lengthOfLastWord("Hello World");
    cout << res << endl;

    res = s.lengthOfLastWord("  ");
    cout << res << endl;

    res = s.lengthOfLastWord("bbda ");
    cout << res << endl;

    return 0;
}