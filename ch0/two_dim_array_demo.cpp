#include <iostream>

using std::cout;
using std::endl;

//Returns an array that contains the sum of elements in each row of a two-dimensional array
int* sum_each_row(int x[][4], int num_rows)
{
    int* result = new int[num_rows];
    for(int r = 0; r < num_rows; r++)
    {
        result[r] = 0;
        for(int c = 0; c < 4; c++)
        {
            result[r] += x[r][c];
        }
    }
    return result;
}

int main()
{
    int my_stuff[2][4] = {{1, 5, 3, 9}, {2, 8, 22, 8}};
    int* sums =sum_each_row(my_stuff, 2);
    for(int i = 0; i < 2; i++)
    {
        cout<<"sums["<<i<<"] = "<<sums[i]<<endl;
    }
    return 0;
}