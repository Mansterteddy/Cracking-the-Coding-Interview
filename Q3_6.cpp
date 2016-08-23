//Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented.
//The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>

class MyStack
{
    public:
        MyStack()
        {
        }
        ~MyStack()
        {
        }
        void push(T value)
        {
            if(s1.empty()) s1.push(value);
            else
            {
                while(!s1.empty() && s1.top() > value )
                {
                    T out = s1.top();
                    s1.pop();
                    s2.push(out);
                }
                s1.push(value);
                while(!s2.empty())
                {
                    T out = s2.top();
                    s2.pop();
                    s1.push(out);
                }
            }
            cout<<"Size: "<<s1.size()<<endl;
        }
        void pop()
        {
            s1.pop();
        }
        T top()
        {
            return s1.top();
        }
        void print()
        {
            int length = s1.size();
            for(int i = 0; i < length; i++)
            {
                T out = s1.top();
                s2.push(out);
                s1.pop();
                cout<<out<<" ";
            }
            cout<<endl;
            for(int i = 0; i < length; i++)
            {
                T out = s2.top();
                s1.push(out);
                s2.pop();
            }
        }
    private:
        stack<T> s1, s2;
};

int main()
{
    MyStack<int> s;
    for(int i = 10; i > 0; i-=2)
    {
        s.push(i);
    }
    s.print();
    for(int i = 1; i < 10; i+=2)
    {
        s.push(i);
    }
    s.print();
    return 0;
}