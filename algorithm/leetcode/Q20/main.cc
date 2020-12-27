#include <stack>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isValid(string s){
            stack<char> left_stack;

            for(int i = 0; i < s.length(); ++i){
                if(s[i] == '(' || s[i] == '[' ||s[i] == '{'){
                    left_stack.push(s[i]);
                }
                else{
                    if(s[i] == ')'){
                        if(left_stack.size() == 0)
                            return false;
                        else if(left_stack.top() == '(')
                            left_stack.pop();
                        else
                            return false;
                    }
                    else if(s[i] == ']'){
                        if(left_stack.size() == 0)
                            return false;
                        else if(left_stack.top() == '[')
                            left_stack.pop();
                        else
                            return false;
                    }
                    else if(s[i] == '}'){
                        if(left_stack.size() == 0)
                            return false;
                        else if(left_stack.top() == '{')
                            left_stack.pop();
                        else
                            return false;
                    }
                }
            }

            if(left_stack.size() != 0)
                return false;
            else
                return true;
        }
};

int main(){

    Solution s = Solution();

    string str = "()";
    bool res = s.isValid(str);
    cout << res << endl;

    str = "()[]{}";
    res = s.isValid(str);
    cout << res << endl;


    return 0;
}