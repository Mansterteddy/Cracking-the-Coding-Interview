//Given a sorted array of n integers that has been rotated an unknown number of times,
//given an O(log n) algorithm that finds an element in the array. 
//You may assume that the array was originally sorted in increasing order. 
//EXAMPLE:
//Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
//Output: 8 (the index of 5 in the array)
#include <iostream>

using namespace std;

/*int find_pos(int *a, int start, int end, int find)
{
    cout<<start<<" "<<end<<" "<<(start + end) / 2<<endl;
    if(find == a[(start + end) / 2]) return (start + end) / 2;
    else if(find > a[(start + end) / 2])
    {
        find_pos(a, (start + end) / 2 + 1, end, find);
    }
    else
    {
        find_pos(a, start, (start + end) / 2 - 1, find);
    }

}*/

int find_pos(int *a, int start, int end, int find)
{
    cout<<"Mid: "<<(start + end) / 2<<" start: "<<start<<" end: "<<end<<endl;
    if(a[start] == find) return start;
    if(a[(start + end) / 2] == find) return (start + end) / 2;
    if(a[end] == find) return end;
    if(a[start] == a[(start + end) / 2])
    {
        cout<<"Enter 1"<<endl;
        if(a[start] == find)
        {
            return start;
        }
        else
        {
            cout<<"No answer!"<<endl;
            return -1;
        }
    }
    else if(a[start] < a[(start + end) / 2])
    {
        cout<<"Enter 2: start"<<a[start]<<" mid: "<<a[(start + end) / 2]<<endl;
        if(find > a[(start + end) / 2])
        {
            find_pos(a, (start + end) / 2 + 1, end, find);
        }
        else if(find > a[start])
        {
            find_pos(a, start + 1, (start + end) / 2 - 1, find);
        }
        else
        {
            find_pos(a, (start + end) / 2 + 1, end, find);
        }
    }
    else
    {
        //a[start] > a[(start + end) / 2]
        cout<<"Enter 3: start"<<a[start]<<" mid: "<<a[(start + end) / 2]<<endl;
        if(find > a[start])
        {
            find_pos(a, start, (start + end) / 2 - 1, find);
        }
        else if(find < a[(start + end) / 2])
        {
            find_pos(a, start, (start + end) / 2 - 1, find);
        }
        else
        {
            find_pos(a, (start + end) / 2 + 1, end, find);
        }
    }
}

int main()
{
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout<<find_pos(a, 0, 11, 3);

    return 0;
}