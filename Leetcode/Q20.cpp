//Given a string containing just the characters ( ) { } [ ], determine if the input string is valid
//The brackets must close in the correct order. 

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