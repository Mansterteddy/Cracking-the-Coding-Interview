//Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
//Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
//Implement a data structure SetOfStacks that mimics this.    
//SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity.  
//SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same valuse as it would if there were just a single stack). 
//FOLLOW UP
//Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

//就是要注意一些实现细节，当某一个栈满了以后，就不能再push了，继续push，需要在后面的栈上push。检测整个栈是否满时，也要遍历所有的子栈。
#include <iostream>

using namespace std;

const int STACK_SIZE = 10;
const int STACK_NUM = 10;

class stack
{
    private:
        int *buf;
        int cur;
        int capacity;
    public:
        stack(int capa = STACK_SIZE)
        {
            buf = new int[capa];
            cur = -1;
            capacity = capa;
        }
        ~stack()
        {
            delete[] buf;
        }
        void push(int val)
        {
            buf[++cur] = val;
        }
        void pop()
        {
            --cur;
        }
        int top()
        {
            return buf[cur];
        }
        bool empty()
        {
            return cur == -1;
        }
        bool full()
        {
            return cur == capacity - 1;
        }
        void print()
        {
            for(int i = 0; i < cur; i++)
            {
                cout<<buf[i]<<endl;
            }
        }
};

//Without popAt()
class SetOfStacks
{
    private:
        stack *st;
        int cur;
        int capacity;
    public:
        SetOfStacks(int capa = STACK_NUM)
        {
            st = new stack[capa];
            cur = 0;
            capacity = capa;
        }
        ~SetOfStacks()
        {
            delete[] st;
        }
        void push(int val)
        {
            if(st[cur].full()) ++cur;
            st[cur].push(val);
        }
        void pop()
        {
            if(st[cur].empty()) --cur;
            st[cur].pop();
        }
        int top()
        {
            if(st[cur].empty()) --cur;
            return st[cur].top();
        }
        bool empty()
        {
            if(cur == 0) return st[0].empty();
            else return false;
        }
        bool full()
        {
            if(cur == capacity - 1) return st[cur].full();
            else return false;
        }
};

class SetOfStacks_1
{
    private:
        stack *st;
        int cur;
        int capacity;
    public:
        SetOfStacks_1(int capa = STACK_NUM)
        {
            st = new stack[capa];
            cur = 0;
            capacity = capa;            
        }
        ~SetOfStacks_1()
        {
            delete[] st;
        }
        void push(int value)
        {
            if(st[cur].full()) cur++;
            st[cur].push(value);
        }
        void pop()
        {
            while(st[cur].empty()) cur--;
            st[cur].pop();
        }
        void popAt(int index)
        {
            if(st[index].empty())
            {
                cout<<"Index: "<<index<<" empty!"<<endl;
            }
            else
            {
                st[index].pop();
            }
        }
        bool empty()
        {
            while(cur != -1 && st[cur].empty()) --cur;
            return (cur == -1);
        }
        bool full()
        {
            bool flag = true;
            for(int i = 0; i < capacity; i++)
            {
                if(!st[i].full()) flag = false;
            }
            return flag;
        }
        int top()
        {
            while(st[cur].empty()) cur--;
            return st[cur].top();
        }
        void print(int index)
        {
            cout<<"Print Index: "<<index<<endl;
            st[index].print();
        }
        
};

int main()
{
    SetOfStacks sos;
    for(int i = 0; i < 99; i++)
    {
        sos.push(i);
        //cout<<"Stack top: "<<sos.top()<<endl;
    }
    cout<<"Check full: "<<sos.full()<<endl;

    SetOfStacks_1 sos_1;
    for(int i = 0; i < 100; i++)
    {
        sos_1.push(i);
        //cout<<"Stack top: "<<sos_1.top()<<endl;
    }
    cout<<"Check full: "<<sos_1.full()<<endl;
    sos_1.print(5);
    sos_1.popAt(5);
    sos_1.print(5);
    sos_1.popAt(5);
    sos_1.print(5);
    cout<<"Check full: "<<sos_1.full()<<endl;
  
    return 0;
}