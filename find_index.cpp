#include <iostream>

using namespace std;

int find_index(int *d, int val, int start, int end)
{
    //d是个递增序列，找出val在d中的位置
    if(start == end) return start;
    if(val <= d[(start + end) / 2]) 
    {
        find_index(d, val, start, (start + end) / 2);
    }
    else
    {
        find_index(d, val, (start + end) / 2 + 1, end);
    }
}

int main()
{
    int d[] = {56, 60, 75};
    cout<<find_index(d, 100, 0, 2)<<endl;
    return 0;
}
