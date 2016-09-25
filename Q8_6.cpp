//Implement the "paint fill" function that one might see on many image editing programs. 
//That is, given a screen (represented by 2-dimensional array of Colors), a point, and a new color, 
//fill in the surrounding area until you hit a border of that color.
#include <iostream>

using namespace std;

void paint_fill(int a[][4], int row, int col, int border, int color)
{
    if(row < 0 || row >= border || col < 0 || col >= border)
    {
        cout<<"Reach Border!"<<endl;
        return;
    }

    if(a[row][col] != 0)
    {
        cout<<"Already Painted!"<<endl;
        return;
    }
    a[row][col] = color;
    paint_fill(a, row - 1, col - 1, border, color);
    paint_fill(a, row - 1, col, border, color);
    paint_fill(a, row - 1, col + 1, border, color);
    paint_fill(a, row, col - 1, border, color);
    paint_fill(a, row, col + 1, border, color);
    paint_fill(a, row + 1, col - 1, border, color);
    paint_fill(a, row + 1, col, border, color);
    paint_fill(a, row + 1, col + 1, border, color);

}

int main()
{
    int a[][4] = {{3, 3, 3, 3},{0, 0, 0, 0}, {0, 0, 0, 0}, {2, 2, 2, 2}};
    paint_fill(a, 1, 1, 4, 1);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<"Color: "<<a[i][j]<<endl;
        }
    }
    return 0;
}