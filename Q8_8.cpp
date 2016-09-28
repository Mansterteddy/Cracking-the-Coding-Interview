//Write an algorithm to print all ways of arranging eight queens on a chess board, so that none of them share the same row, column or diagonal.
#include <iostream>

using namespace std;

//八皇后问题一共92种
//使用传统的暴力枚举法，一共2^64种可能，算不完
int num = 0;

void print(int a[8][8])
{
    num++;
    cout<<"The chess is: "<<endl;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(int a[8][8], int row, int col)
{
    bool flag = true;
    if(row == 0) return true;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(a[i][j] == 1 && j == col)
            {
                flag = false;
            }
            else if(a[i][j] == 1)
            {
                //if(j == col - 1 || j == col + 1)
                if((row - i) == (col - j) || (row - i) == (j - col))
                {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

//对角线指的是一整条线 而非相邻的四个元素


void assign(int a[8][8], int row)
{
    if(row == 7)
    {
        for(int i = 0; i < 8; i++)
        {
            bool flag = check(a, 7, i);
            if(flag)
            {
                a[7][i] = 1;
                print(a);
                a[7][i] = 0;
            }
        }
        return;
    }

    for(int i = 0; i < 8; i++)
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
    int a[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
    //int a[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    //memset(col_check, 0, sizeof(col_check));
    assign(a, 0);
    cout<<"Solution's number is: "<<num<<endl;
    return 0;
}