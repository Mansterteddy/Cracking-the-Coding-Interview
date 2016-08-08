//Given an image represented by an N*N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
#include <iostream>

using namespace std;

//在C语言中，数组不可以作为参数来传递，但是可以通过传递指向数组初始元素的指针，使得在函数内部操作数组成为可能
//由于传递的只是指针，因此函数并不知道调用方数组的元素个数
//main函数中array的类型是int的数组 因此可以用sizeof运算符取得数组元素的个数
//但是在函数中 array的类型是指向int的指针 因此sizeof只能取得指针自身的大小
//因此传参时 应当传入指针和数组的大小
//要求顺时针旋转 可以先逆时针旋转 然后做对称变换
void rotate(int (*a)[4], int length)
{
    cout<<"Length:"<<length<<endl;
    
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }   
    
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length / 2; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[i][length - j - 1];
            a[i][length - j - 1] = temp;
        }
    }
}


int main()
{
    int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int length = sizeof(a) / sizeof(a[0]);
    
    rotate(a, length);
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            cout<<a[i][j]<<" ";
        }
            cout<<endl;
    }
    
}

