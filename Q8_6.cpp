//Implement the "paint fill" function that one might see on many image editing programs. 
//That is, given a screen (represented by 2-dimensional array of Colors), a point, and a new color, 
//fill in the surrounding area until you hit a border of that color.
#include <iostream>

using namespace std;

//可以使用递归和迭代两种思路，迭代就是使用BFS，只要队列不为空，就一直处理。
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

enum color{
    red, yellow, blue, green
};

//遇到=c的 就停止，否则会把整个图填充完 因为只要不是c的 都被改成c 不是c的周边被c包围 那么就不会扩散到这个范围外面去
bool paint_fill_1(color **screen, int m, int n, int x, int y, color c)
{
    if(x < 0 || x >= m || y < 0 || y >= n) return false;
    if(screen[x][y] == c) return false;
    else
    {
        screen[x][y] = c;
        paint_fill_1(screen, m, n, x - 1, y, c);
        paint_fill_1(screen, m, n, x + 1, y, c);
        paint_fill_1(screen, m, n, x, y - 1, c);
        paint_fill_1(screen, m, n, x, y + 1, c);
    }
    return true;
}

int main()
{
    int a[][4] = {{3, 3, 3, 3},{3, 3, 0, 0}, {0, 0, 0, 2}, {2, 2, 2, 2}};
    paint_fill(a, 1, 3, 4, 1);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<"Color: "<<a[i][j]<<endl;
        }
    }

    color **screen = new color*[4];
    for(int i = 0; i < 4; i++)
    {
        screen[i] = new color[4];
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            screen[i][j] = red;
        }
    }

    paint_fill_1(screen, 4, 4, 1, 1, blue);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}