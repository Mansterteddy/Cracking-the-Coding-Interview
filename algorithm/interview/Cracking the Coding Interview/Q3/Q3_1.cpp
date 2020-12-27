//Describe how you could use a single array to implement three stacks.
#include <iostream>

using namespace std;

//将数组平分成三个部分，每个部分维护一个栈顶指针，根据具体是对哪个栈进行操作，用栈顶指针加上相应的偏移量即可
class stack3
{
    public:
        stack3(int size = 300)
        {
            buf = new int[size * 3];
            ptop[0] = ptop[1] = ptop[2] = -1;
            this->size = size;
        }

        ~stack3()
        {
            delete[] buf;
        }

        void push(int stackNum, int val)
        {
            int idx = stackNum * size + ptop[stackNum] + 1;
            buf[idx] = val;
            ++ptop[stackNum];
        }

        void pop(int stackNum)
        {
            --ptop[stackNum];
        }

        int top(int stackNum)
        {
            int idx = stackNum * size + ptop[stackNum];
            return buf[idx];
        }

        bool empty(int stackNum)
        {
            return ptop[stackNum] == -1;
        }

    private:
        int *buf;
        int ptop[3];
        int size;
};

//也可以数组不分段，无论哪个栈入栈，都一次往这个数组里存放，除了维护每个栈的栈顶指针外，还要维护每个栈中，每个元素指向前一个元素的指针
//这样一来，某个栈顶元素出栈后，它就能正确地找到下一个栈顶元素
//但是这样的实现，会造成空间的浪费，在堆栈出栈后，中间位置的空间将不再会被利用到
//也存在相同的方法，但是更省空间的实现，但是实现起来更加复杂：每一次pop操作后，检查该元素索引是否小于cur，如果是，将cur更新到该索引，否则cur不变
//每次执行完push操作后，cur要沿着数组依次向后1查找，直到找到第一个空的空间。
struct Node
{
    int val, preIDx;
};

class stack3_1
{
    public:
        stack3_1(int totalSize = 900)
        {
            buf = new Node[totalSize];
            ptop[0] = ptop[1] = ptop[2] = -1;
            this->totalSize = totalSize;
            cur = 0;
        }
        ~stack3_1()
        {
            delete[] buf;
        }

        void push(int stackNum, int val)
        {
            buf[cur].val = val;
            buf[cur].preIDx = ptop[stackNum];
            ptop[stackNum] = cur;
            cur++;
        }

        void pop(int stackNum)
        {
            ptop[stackNum] = buf[ptop[stackNum]].preIDx;
        }

        int top(int stackNum)
        {
            return buf[ptop[stackNum]].val;
        }

        bool empty(int stackNum)
        {
            return ptop[stackNum] == -1;
        }
        
        private:
            Node *buf;
            int ptop[3];
            int totalSize;
            int cur;
};


int main()
{
    stack3 mystack;
    for(int i = 0; i < 10; i++)
    {
        mystack.push(0, i);
    }
    for(int i = 10; i < 20; i++)
    {
        mystack.push(1, i);
    }
    for(int i = 100; i < 110; ++i)
    {
        mystack.push(2, i);
    }
    for(int i = 0; i < 3; i++)
    {
        cout<<mystack.top(i)<< " ";
    }

    cout<<endl;

    for(int i = 0; i < 3; i++)
    {
        mystack.pop(i);
        cout<<mystack.top(i)<<" ";
    }

    mystack.push(0, 111);
    mystack.push(1, 222);
    mystack.push(2, 333);

    for(int i = 0; i < 3; i++)
    {
        cout<<mystack.top(i)<<" ";
    }

    return 0;
}
