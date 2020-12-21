#include <vector>
#include <iostream>

using namespace std;

class MinStack{
    public:

        vector<int> stack;
        vector<int> min_stack;

        MinStack(){

        }

        void push(int x){
            stack.push_back(x);
            if(min_stack.size() == 0){
                min_stack.push_back(x);
            }
            else if(x <= min_stack[min_stack.size()-1]){
                min_stack.push_back(x);
            }
        }

        void pop(){
            int cur_val = stack[stack.size()-1];
            stack.pop_back();
            if(cur_val == min_stack[min_stack.size()-1]){
                min_stack.pop_back();
            }

        }

        int top(){
            return stack[stack.size()-1];
        }

        int getMin(){

            return min_stack[min_stack.size()-1];
        }
};

int main(){

    cout << "Leetcode Q155." << endl;

    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int res = minStack->getMin();
    cout << res << endl;
    minStack->pop();
    res = minStack->top();
    cout << res << endl;
    res = minStack->getMin();
    cout << res << endl;

    return 0;
}