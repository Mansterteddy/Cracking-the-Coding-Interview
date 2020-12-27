//Implement a MyQueue class which implements a queue using two stacks

//一个栈用于push_front pop_front 一个栈用于push_back pop_back 如果某个栈空了，但是还需要pop，就将另一个栈的内容移过来。
#include <iostream>
#include <stack>
using namespace std;

template<typename T>

class MyQueue
{
    public:
        MyQueue()
        {    
        }
        ~MyQueue()
        {
        }
        void push(T val)
        {
            s1.push(val);
        }
        void pop()
        {
            move(&s1, &s2);
            s2.pop();   
        }
        T front()
        {
            move(&s1, &s2);
            return s2.top();
        }
        T rear()
        {
            move(&s2, &s1);
            return s1.top();
        }
        int size()
        {
            return s1.size() + s2.size();
        }
        bool empty()
        {
            return s1.empty() && s2.empty();
        }
        void move(stack<T> *src, stack<T> *dst)
        {
            if(dst->empty())
            {
                while(!src->empty())
                {
                    dst->push(src->top());
                    src->pop();
                }
            }
        }
    private:
        stack<T> s1, s2;
};

int main()
{
    MyQueue<int> q;
    for(int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    cout<<q.front()<<" "<<q.rear()<<endl;

    q.pop();
    q.push(10);

    cout<<q.front()<<" "<<q.rear()<<endl;

    cout<<q.size()<<endl;
    return 0;
}