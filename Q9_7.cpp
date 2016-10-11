//A circus is designing a tower routine consisting of people standing atop one another's shoulders. 
//For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. 
//Given the heights and weights of each person in the circus, 
//Write a method to compute the largest possible number of people in such a tower. 
/*
EXAMPLE:

Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)

Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100;
struct person
{
    int h, w;
};
person p[maxn];
int d[maxn];

bool cmp(person p1, person p2)
{
    if(p1.h == p2.h) return p1.w < p2.w;
    else return p1.h < p2.h;
}

//多指数排序 先按照一个指标排序后 然后根据另一个目标 找到最长递增序列即可 后面这个问题是一个动态规划问题
//从0到第i个元素 第i个元素最大长度为 小于i元素的第一个元素的最大长度 + 1
int lis(person p[], int n)
{
    d[0] = 1;
    for(int i = 1; i < n; i++)
    {
        int max = 1;
        for(int j = 0; j < i; j++)
        {
            if(p[i].w > p[j].w)
            {
                if(d[j] + 1 >= max) max = d[j] + 1;
            }
        }
        d[i] = max;
    }

    return d[n - 1];
}



int main()
{
    int height[] = {65, 70, 56, 75, 60, 68};
    int weight[] = {100, 150, 90, 190, 95, 110};
    int len = sizeof(height) / sizeof(height[0]);
    for(int i = 0; i < len; i++)
    {
        p[i].h = height[i];
        p[i].w = height[i];
    }
    sort(p, p + len, cmp);
    cout<<lis(p, len)<<endl;
    return 0;
}