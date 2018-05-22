//Given a string containing just the characters ( ) { } [ ], determine if the input string is valid
//The brackets must close in the correct order. 
//这道题很简单，遍历整个string字符串，当遇到(, [, {时，入栈，当遇到), ], }时，查看栈中前一位置是否是对应的括号，如果不是，return false。最后查看栈中是否为空，如果为空，return true，否则，return false。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool isValid(string s)
        {
            if(s.empty()) return true;
            
            vector<char> st;

            st.push_back(s[0]);

            for(int i = 1; i < s.length(); i++)
            {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push_back(s[i]);
                }
                else
                {
                    if(s[i] == ')')
                    {
                        if(st.empty())
                        {
                            return false;
                        }
                        else if(st.back() == '(')
                        {
                            st.pop_back();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if(s[i] == ']')
                    {
                        if(st.empty())
                        {
                            return false;
                        }
                        else if(st.back() == '[')
                        {
                            st.pop_back();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(st.empty())
                        {
                            return false;
                        }
                        else if(st.back() == '{')
                        {
                            st.pop_back();
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }

            if(st.empty()) return true;
            else return false;
            
        }
};

int main()
{
    string s1 = "(())";
    Solution s;
    bool flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{[()]}";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{[()}";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{[(";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{[]()}";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{}[]()";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{[]}()";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{}[](";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;

    s1 = "{}(";
    flag = s.isValid(s1);
    cout<<"Ans is "<<flag<<endl;
    return 0;
}