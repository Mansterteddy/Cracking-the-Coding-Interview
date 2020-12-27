//In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower.
//The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g. each disk sits on top of an even larger one).  
//You have the following constraints:
//Only one disk can be moved at a time.
//A disk is slid off the top of one rod onto the next rod.
//A disk can only be placed on top of a larger disk.   
//Write a program to move the disks from the first rod to the last using Stacks.

//汉诺塔的实现分为两种：1、直接使用栈；2、递归处理。
#include <iostream>
#include <stack>
using namespace std;

struct op
{
    int begin, end;
    char src, bri, dst;
    op(){}
    op(int pbegin, int pend, int psrc, int pbri, int pdst):begin(pbegin), end(pend), src(psrc), bri(pbri), dst(pdst)
    {
    }
};

void hanoi(int n, char src, char bri, char dst)
{
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, bri, dst));
    while(!st.empty())
    {
        tmp = st.top();
        st.pop();
        if(tmp.begin != tmp.end)
        {
            st.push(op(tmp.begin, tmp.end - 1, tmp.bri, tmp.src, tmp.dst));
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));
            st.push(op(tmp.begin, tmp.end - 1, tmp.src, tmp.dst, tmp.bri));
        }
        else
        {
            cout<<"Move Disk "<<tmp.begin<<" from "<<tmp.src<<" to "<<tmp.dst<<endl;
        }
    }
}


class Stacks
{
    public:
        Stacks(int size = 20)
        {
            this->size = size;
            buf = new int[size];
            cur = -1;
        }

        ~Stacks()
        {
            delete []buf;
        }

        void push(int value)
        {
            cur++;
            buf[cur] = value;
        }

        int pop()
        {
            int value = buf[cur];
            cur--;
            return value;
        }

        int top()
        {
            return buf[cur];
        }

        bool empty()
        {
            return (cur == -1);
        }

        void print()
        {
            for(int i = 0; i <= cur; i++)
            {
                cout<<buf[i]<<" ";
            }
            cout<<endl;
        }

    private:
        int cur;
        int *buf;
        int size;
};

void Hanoi_Tower(int start_plate, int end_plate, int first_stack, int end_stack, int middle_stack)
{
    if(start_plate == end_plate)    cout<<"Moving: "<<start_plate<<" from "<<first_stack<<" to "<<end_stack<<" through "<<middle_stack<<endl;
    else
    {
          Hanoi_Tower(start_plate, end_plate - 1, first_stack, middle_stack, end_stack);
          Hanoi_Tower(end_plate, end_plate, first_stack, end_stack, middle_stack);
          Hanoi_Tower(start_plate, end_plate - 1, middle_stack, end_stack, first_stack);
    }
}

void Hanoi_Tower_1(int num, Stacks* first_stack, Stacks* end_stack, Stacks* middle_stack)
{

    if(num == 1)
    {
        int exchange = first_stack->pop();
        cout<<"Exchange: "<<exchange<<endl;
        end_stack->push(exchange);
    }    
    else
    {
        Hanoi_Tower_1(num - 1, first_stack, middle_stack, end_stack);
        Hanoi_Tower_1(1, first_stack, end_stack, middle_stack);
        Hanoi_Tower_1(num - 1, middle_stack, end_stack, first_stack);
    }
}

int main()
{
    //Hanoi_Tower(1, 3, 1, 3, 2);
    Stacks first_stack, middle_stack, end_stack;
    int range = 4;
    for(int i = range; i > 0; i--)
    {
        first_stack.push(i);
    }
    cout<<"Initial:"<<endl;
    first_stack.print();
    Hanoi_Tower_1(range, &first_stack, &middle_stack, &end_stack);
    cout<<"First Stack: "<<endl;
    first_stack.print();
    cout<<"Middle Stack: "<<endl;
    middle_stack.print();
    cout<<"End Stack: "<<endl;
    end_stack.print();

    hanoi(3, 'A', 'B', 'C');
    return 0;
}