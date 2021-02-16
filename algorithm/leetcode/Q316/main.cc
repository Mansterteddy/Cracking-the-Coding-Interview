#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string removeDuplicateLetters(string s){
            vector<int> vis(26), num(26);

            for(char ch : s){
                num[ch - 'a'] += 1;
            }

            string stk;
            for(char ch : s){
                if(!vis[ch - 'a']){
                    while(!stk.empty() && stk.back() > ch){
                        if(num[stk.back() - 'a'] > 0){
                            vis[stk.back() - 'a'] = 0;
                            stk.pop_back();
                        }
                        else{
                            break;
                        }
                    }
                    vis[ch - 'a'] = 1;
                    stk.push_back(ch);
                }
                num[ch - 'a'] -= 1;
            }

            return stk;

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