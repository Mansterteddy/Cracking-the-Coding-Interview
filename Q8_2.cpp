//Imagine a robot sitting on the upper left hand corner of an NxN grid. 
//The robot can only move in two directions: right and down. 
//How many possible paths are there for the robots?
//FOLLOW UP 
//Imagine certain squares are "off limits", such that the robot can not step on them. 
//Design an algorithm to get all possible paths for the robot. 
#include <iostream>
#include <stack>

using namespace std;

int **t_global = new int*[3];

void test()
{
    //char *cn[] = {"red", "green", "blue"};
    //char cn[][6] = {{'r', 'e', 'd', '\0'}, {'g', 'r', 'e', 'n', 'n', '\0'}, {'b', 'l', 'u', 'e', '\0'}};
    //栈是连续内存，可分配空间较小
    //堆是非连续内存，可分配空间较大
    //对于栈分配内存 不能使用int m = 10; int a[m];这种方式
    //但是int *a = new [m];这种方式就可以

    //定义m * m的数组
    int m = 2;
    //p是指向int*的指针
    int **p;
    //因此m的大小是针对p这个int*的数组的大小
    p = new int*[m];

    int a[] = {1, 2, 3};
    cout<<"Size int: "<<sizeof(a) / sizeof(a[0])<<endl;
    
    
    //定义n * m的数组 m必须是常量
    int n = 2;
    //先括号起来*，则说明声明的是一个指针，指针的内容是一个数组
    //不括号的话，声明的是一个数组，内容是指针
    int (*pp)[2] = new int [n][2];

    //定义n * n的数组
    //动态创建一个大小为n的内容为int*的数组
    int **tt = new int*[n];
    for(int i = 0; i < n; i++)
    {
        //对int*数组中 每一个元素是一个int*，赋予一个动态分配的int数组
        tt[i] = new int[n];
    }
}

int get_v(int row, int col, int n)
{   
    if(row == n - 1 && col == n - 1) return 1;
    if(row > n - 1 || col > n - 1) return 0;
    if(t_global[row][col] == 1) return 0;
    int res = get_v(row + 1, col, n) + get_v(row, col + 1, n);
    return res;
}

void paths(int n)
{
    cout<<"Enter"<<endl;
    //动态声明数组大小
    int **t = new int*[n];
    for(int i = 0; i < n; i++)
    {
        t[i] = new int[n];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            t[i][j] = 0;
        }
    }

    t[0][0] = get_v(0, 1, n) + get_v(1, 0, n);
    cout<<"Result is: "<<t[0][0]<<endl;

}

//解法2 对m * n的格子 因为只能两种方式走路 因此总共要走的路程为 m - 1 + n - 1 从上述步骤中选取m - 1步作为向下走的步数 剩下n - 1步作为向右走的步数 即可确认走路顺序 唯一决定一条路径 这就是简单的排列组合
typedef struct point
{
    int x, y;
}point;

stack<point> sp;
const int MAXN = 20;
int g[MAXN][MAXN];
point vp[MAXN+MAXN];

bool get_path(int m, int n)
{
    point p;
    p.x = n;
    p.y = m;
    sp.push(p);
    if(n == 1 && m == 1) return true;
    bool suc = false;
    if(m > 1 && g[m-1][n])
    {
        suc = get_path(m - 1, n);
    }
    if(!suc && n > 1 && g[m][n-1])
    {
        suc = get_path(m, n - 1);
    }
    if(!suc) sp.pop();
    return suc;
}

//递归调用是通过栈实现的，具体实现可以参考Q3_4，汉诺塔的堆栈实现。
//打印所有路径
void print_paths(int m, int n, int M, int N, int len)
{
    if(g[m][n] == 0) return;
    point p;
    p.x = n;
    p.y = m;
    //记录整个路程，当重新寻找path时，会被覆盖，事实上len记录当前走到第几步
    //因为此方法只能右走或者下走，因此走到终点，无论哪种路线，步数都是一样的，因此可以使用数组来记录路径。
    vp[len] = p;
    len++;
    if(m == M && n == N)
    {
        for(int i = 0; i < len; i++)
        {
            cout<<"("<<vp[i].y<<", "<<vp[i].x<<")"<<" ";
        }
        cout<<endl;
    }
    else
    {
        print_paths(m, n+1, M, N, len);
        print_paths(m+1, n, M, N, len);
    }
}

int main()
{
    int n = 3;
    for(int i = 0; i < n; i++)
    {
        t_global[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            t_global[i][j] = 0;
        }
    }
    t_global[1][2] = 1;

    paths(n);

    int M = 3, N = 3;
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            g[i][j] = 1;
        }
    }
    cout<<"one of the paths: "<<endl;
    get_path(M, N);
    while(!sp.empty())
    {
        point p = sp.top();
        cout<<"("<<p.y<<". "<<p.x<<")"<<" ";
        sp.pop();
    }
    cout<<endl;

    cout<<"All paths: "<<endl;
    print_paths(1, 1, M, N, 0);
    return 0;
}