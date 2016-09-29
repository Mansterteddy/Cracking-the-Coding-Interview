//You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
#include <iostream>

using namespace std;

//从前往后处理比较麻烦，不如从后向前做
void merge(int *a, int size_a, int *b, int size_b)
{
    int k = size_a + size_b - 1;
    int i = size_a - 1, j = size_b - 1;
    while(i >= 0 && j >= 0)
    {
        if(a[i] > b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }
    while(j >= 0) a[k--] = b[j--];
    //如果最后i不为0，没问题，因为本身已经排好序了，而且正好在对应的位置上
}

//非原地合并
void merge_1(int *a, int size_a, int *b, int size_b)
{
    int *c = new int[size_a + size_b];
    int start_a = 0;
    int start_b = 0;
    for(int i = 0; i < size_a + size_b; i++)
    {
        if(start_a == size_a)
        {
            for(; start_b < size_b; start_b++)
            {
                c[i] = b[start_b];
                i++;
            }
            break;
        }
        else if(start_b == size_b)
        {
            for(; start_a < size_a; start_a++)
            {
                c[i] = a[start_a];
                i++;
            }
            break;
        }
        else if(a[start_a] > b[start_b])
        {
            c[i] = b[start_b];
            start_b++;
        }
        else
        {
            c[i] = a[start_a];
            start_a++;
        }
    }
    for(int i = 0; i < size_a + size_b; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}

//假设一个数组 前半部分和后半部分都有序 但是整体无序 那么如何不使用额外空间使得整体有序
//首先对比前半部分第一个元素，和后半部分第一个元素，更小的那个，就是整体最小的元素
//随后把第一位放置最小的元素，然后将另一个元素放到后半部分，并将这个元素插入到后半部分合适的部分，保证后半部分整体有序
//随后比较前半部分第二个元素和后半部分第一个元素 以此类推
//当完成前半部分排序后，后半部分一直保持有序 那么整体也就有序了

int main()
{
   /* int x = 0;
    int *y = &x;
    *y = 1;
    cout<<"x: "<<x<<endl;*/

    //int *a = new [10];
    int a[10] = {1, 3, 5, 7};
    int b[3] = {2, 4, 6};
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);
    merge(a, 4, b, size_b);
    merge_1(a, 4, b, size_b);
    for(int i = 0; i < size_a; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}