//Write a method to generate the nth Fibonacci number
#include <iostream>

using namespace std;

int Fibonacci_Bottom_Up(int n)
{
    int f1 = 1;
    int f2 = 1;
    int fn = 0;
    for(int i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    return fn;

}

int Fibonacci_Top_Down(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 1;
    int fn = Fibonacci_Top_Down(n-1) + Fibonacci_Top_Down(n-2);

    return fn;
}


//以上方法都是O(n)的时间复杂度
//最好的方法是O(logn)的时间复杂度
//2*2矩阵 第一行 1 0 第二行 1 1，初始列向量 f2 f1，两者相乘 得到 f2 f3
//C语言无法返回多维数组，要返回多维数组，有两种方式，1、构造一个结构体，返回结构体的指针；2、依靠传参返回参数的方法，不依靠返回值。
void mul(int c[2][2], int a[2][2], int b[2][2])
{
    int t[4];
    t[0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    t[1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    t[2] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    t[3] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    c[0][0] = t[0];
    c[0][1] = t[1];
    c[1][0] = t[2];
    c[1][1] = t[3];
}

void pow(int s[2][2], int a[2][2], int n)
{
    while(n > 0)
    {
        if(n & 1) mul(s, s, a);
        mul(a, a, a);
        n >>= 1;
    }
}

int Fibonacci(int n)
{
    if(n < 1) return -1;
    if(n == 1 || n == 2) return 1;

    int a[2][2] = {{1, 1}, {1, 0}};
    int s[2][2] = {{1, 0}, {0, 1}};
    pow(s, a, n - 2);
    return s[0][0] + s[0][1];
}

void ret(int (*a)[2])
{
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4; 
}

int main()
{
    cout<<"The nth Fibonacci Number is: "<<Fibonacci_Bottom_Up(10)<<endl;
    cout<<"The nth Fibonacci Number is: "<<Fibonacci_Top_Down(10)<<endl;
    cout<<"The nth Fibonacci Number is: "<<Fibonacci(10)<<endl;
    int a[][2] = {{1, 1}, {0, 1}};
    ret(a);

    
    return 0;
}