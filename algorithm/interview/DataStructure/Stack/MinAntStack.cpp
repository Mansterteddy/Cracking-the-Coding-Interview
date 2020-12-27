//设计一个stack数据结构，使得可以像stack一样push和pop，但是求解min的时候，时间复杂度需要为O(1)，空间复杂度为O(n)。
//Solution：利用空间换时间，设计一个新的stack，用于保存最小值。

#include <iostream>
#include <stack>

using namespace std;

template<typename Item_Type>
class MinAntStack
{
    private:
        stack<Item_Type> raw_stack;
        stack<Item_Type> min_stack;

    public:
        MinAntStack()
        {
            raw_stack = {};
            min_stack = {};
        }

        void push(Item_Type val)
        {
            raw_stack.push(val);

            if(min_stack.size() == 0)
            {
                min_stack.push(val);
            }
            else if(val > min_stack.top())
            {
                min_stack.push(min_stack.top());
            }
            else
            {
                min_stack.push(val);
            }
        }

        void pop()
        {
            Item_Type res = raw_stack.top();
            raw_stack.pop();
            min_stack.pop();
        }

        Item_Type min()
        {
            return min_stack.top();
        }
};

int main()
{
    MinAntStack<int> in;

    in.push(0);
    cout << in.min() << endl;
    in.push(1);
    cout << in.min() << endl;
    in.push(-1);
    cout << in.min() << endl;
    in.pop();
    cout << in.min() << endl;

    return 0;
}