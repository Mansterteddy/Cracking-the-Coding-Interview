/*
给定一个入栈序列，和一个出栈序列，确定这两个序列是否可以指代同一个序列的入栈和出栈过程。
这道题我最开始考虑，对入栈序列，列举所有的case，然后看出栈序列是否在case中，
后来面试官提醒了一下，中间可以加一个栈来保存中间状态，于是这道题就变成了模拟出栈入栈过程了，
遍历入栈序列，当和出栈序列元素不等时，压栈，相等时，出栈，最后如果中间栈不为空，就为false，
否则就为true。
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> in = {1, 2, 3, 4};
    vector<int> out = {2, 1, 3, 4};
    stack<int> mid;

    if(in.size() != out.size())
    {
        cout<<"False!";
        return 0;
    }
    
    int j = 0;
    for(int i = 0; i < in.size(); ++i)
    {
        if(in[i] == out[j])
        {
            j++;
            while(!(mid.size() == 0 || mid.top() != out[j]))
            {
                mid.pop();
                j++;
            }

        }
        else
        {
            mid.push(in[i]);
        }
    }

    for(; j < out.size(); j++)
    {
        if(mid.top() != out[j])
        {
            cout<<"False!"<<endl;
            return 0;
        }
        else
        {
            mid.pop();
        }
    }

    cout<<"True!"<<endl;

    return 0;
}