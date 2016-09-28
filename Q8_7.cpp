//Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent),
//write code to calculate the number of ways of representing n cents. 
#include <iostream>
#include <vector>

using namespace std;

int number = 0;

//核心是对cents排序，不要出现重复情况
void represent(vector<int> *vec, int res)
{
    if(res < 0) return;
    if(res == 0)
    {
        for(int i = 0; i < vec->size(); i++)
        {
            cout<<(*vec)[i]<<" ";
        }
        cout<<endl;
        number++;
        return;
    }
    if(vec->size() == 0 || vec->back() == 25)
    {
        vec->push_back(25);
        represent(vec, res - 25);
        vec->pop_back();
        vec->push_back(10);
        represent(vec, res - 10);
        vec->pop_back();
        vec->push_back(5);
        represent(vec, res - 5);
        vec->pop_back();
        vec->push_back(1);
        represent(vec, res - 1);
        vec->pop_back();
    }
    else if(vec->back() == 10)
    {
        vec->push_back(10);
        represent(vec, res - 10);
        vec->pop_back();
        vec->push_back(5);
        represent(vec, res - 5);
        vec->pop_back();
        vec->push_back(1);
        represent(vec, res - 1);
        vec->pop_back();
    }
    else if(vec->back() == 5)
    {
        vec->push_back(5);
        represent(vec, res - 5);
        vec->pop_back();
        vec->push_back(1);
        represent(vec, res - 1);
        vec->pop_back();
    }
    else
    {
        vec->push_back(1);
        represent(vec, res - 1);
        vec->pop_back();
    }
}

int main()
{
    vector<int> vec;
    represent(&vec, 25);
    cout<<"The number is: "<<number<<endl;
    return 0;
}