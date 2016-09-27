//Write an algorithm to print all ways of arranging eight queens on a chess board, so that none of them share the same row, column or diagonal.
#include <iostream>

using namespace std;

void print(int a[4][4])
{
    cout<<"The chess is: "<<endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(int a[4][4], int row, int col)
{
    bool flag = true;
    if(row == 0) return true;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(a[i][j] == 1 && j == col)
            {
                flag = false;
            }
            else if(i == row -1 && a[i][j] == 1)
            {
                if(j == col - 1 || j == col + 1)
                {
                    flag = false;
                }
            }
        }
    }
    return flag;
}


void assign(int a[4][4], int row)
{
    if(row == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            bool flag = check(a, 3, i);
            if(flag)
            {
                a[3][i] = 1;
                print(a);
                a[3][i] = 0;
            }
        }
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        if(check(a, row, i))
        {
            a[row][i] = 1;
            assign(a, row + 1);
            a[row][i] = 0;
        } 
    }

}


int main()
{
    //int a[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
    int a[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    assign(a, 0);
    return 0;
}