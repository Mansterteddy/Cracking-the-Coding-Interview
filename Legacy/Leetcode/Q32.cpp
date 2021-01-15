//Given a string containing just the characters '(' and ')', find the length of the lonegst valid (well-formed) parentheses substring. 
//'(()' is '()' which length = 2
//')()())' is '()()' which length = 4

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            stack<pair<char, int>> st;
            vector<int> v(s.size());

            for(int i = 0; i < s.size(); ++i)
            {
                if(i == 0)
                {
                    pair<char, int> son(s[i], i);
                    st.push(son);
                }
                else
                {
                    if(s[i] == ')')
                    {
                        if(st.size() != 0 && st.top().first == '(')
                        {
                            v[i] = 1;
                            v[st.top().second] = 1;
                            st.pop();

                        }
                        else 
                        {
                            pair<char, int> son(s[i], i);
                            st.push(son);
                        }
                    }
                    else 
                    {
                        pair<char, int> son(s[i], i);
                        st.push(son);
                    }
                }
            }

            int res = 0;
            int index = 0;
            int max = 0;

            for(int i = 0; i < v.size(); ++i)
            {
                if(v[i] == 0)
                {
                    res = 0;
                }
                else
                {
                    res += 1;
                    if(res > max) max = res;
                }
            }

            return max;
        }
};

int main()
{
    Solution s;

    string a = "(((((((())()";
    int res = s.longestValidParentheses(a);
    cout<<"res: "<<res<<endl;

    return 0;
}