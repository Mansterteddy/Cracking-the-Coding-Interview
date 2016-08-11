//How would you design a stack which, in additon to push and pop, also has a function min which returns the minimum element?
//Push, pop and min should all operate in O(1) time

//最开始做这道题的时候，很容易进入误区，以为只要空出一位来保留最小值就可以了
//但是要考虑到数据结构是动态的，假如最小值pop出去了，岂不就找不到最小值了？
//可以对栈进行改造，栈中每个元素多保留一位，保存此时元素和元素以前的最小值

#include <iostream>

using namespace std;

const int MAX_INT = ~(1<<31);

struct Node
{
    int value;
    int min;
};

class stack
{
    public:
        stack(int size = 100)
        {
            buf = new Node[size];
            this->size = size;
            top = -1;
        }
        ~stack()
        {
            delete[] buf;
        }
        void push(int value)
        {
            top++;
            buf[top].value = value;
            if(top == 0) buf[top].min = value;
            else
            {
                if(buf[top - 1].min > value) buf[top].min = value;
                else buf[top].min = buf[top - 1].min;
            }
        }
        void pop()
        {
            top--;
        }
        int top_now()
        {
            return buf[top].value;
        }
        int minimum()
        {
            return buf[top].min;
        }

    private:
        Node *buf;
        int size;
        int top;
};

class stack_1
{
    public:
        stack_1(int size = 100)
        {
            buf = new int[size];
            size = this->size;
            cur = -1;
        }
        ~stack_1()
        {
            delete[] buf;
        } 
        void push(int val)
        {
            cur++;
            buf[cur] = val;
        }
        void pop()
        {
            cur--;
        }
        int top()
        {
            return buf[cur];
        }
        bool empty()
        {
            return (cur == -1);
        }

    private:
        int* buf;
        int cur;
        int size;
};

class stack_2
{
    public:
        stack_2()
        {   
        }
        ~stack_2()
        {
        }
        void push(int val)
        {
            stack1.push(val);
            if(stack2.empty()) stack2.push(val);
            else
            {
                if(stack2.top() >= val)
                    stack2.push(val);
            }
        }
        void pop()
        {
            if(stack1.top() == stack2.top()) stack2.pop();
            stack1.pop();
        }
        int top()
        {
            return stack1.top();
        }
        bool empty()
        {
            return stack1.empty();
        }
        int min()
        {
            return stack2.top();
        }

    private:
        stack_1 stack1, stack2;   
};

//第二种方法更省空间
int main()
{
    stack mystack;
    for(int i = 0; i < 10; i++)
    {
        mystack.push(i);
        cout<<"Top: "<<mystack.top_now()<<endl;
        cout<<"Min: "<<mystack.minimum()<<endl;
    }
    for(int i = 0; i < 9; i++)
    {
        mystack.pop();
        cout<<"Top: "<<mystack.top_now()<<endl;
        cout<<"Min: "<<mystack.minimum()<<endl;
    }

    stack_2 mystack_1;
    for(int i = 0; i < 10; i++)
    {
        mystack_1.push(i);
        cout<<"Top: "<<mystack_1.top()<<endl;
        cout<<"Min: "<<mystack_1.min()<<endl;
    }
    for(int i = 0; i < 9; i++)
    {
        mystack_1.pop();
        cout<<"Top: "<<mystack_1.top()<<endl;
        cout<<"Min: "<<mystack_1.min()<<endl;
    }
    return 0;
}