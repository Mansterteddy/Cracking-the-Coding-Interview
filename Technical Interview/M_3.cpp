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