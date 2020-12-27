/*
WY_7
小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死。 
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高


输出描述:
输出一个整数,表示n个学生列队可以获得的最大的疯狂值。

如样例所示: 
当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100。
这是最大的疯狂值了。

输入例子1:
5
5 10 25 40 25

输出例子1:
100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int cal_dis(deque<int> d)
{
    int distance = 0;
    
    for(int i = 1; i < d.size(); ++i)
    {
        distance += abs(d[i]-d[i-1]);
    }
    
    return distance;
    
}

int get_max(vector<int> input)
{
    sort(input.begin(), input.end());
    
    vector<int>::iterator prev = input.begin();
    vector<int>::iterator back = input.end() - 1;
    
    deque<int> d;
    d.push_back(*back);
    back--;
    
    while(prev <= back)
    {
        if(back - prev >= 3)
        {
            d.push_front(*prev);
            prev++;
            d.push_back(*prev);
            prev++;
            d.push_front(*back);
            back--;
            d.push_back(*back);
            back--;
        }
        else if(back - prev == 2)
        {
            d.push_front(*prev);
            prev++;
            d.push_back(*prev);
            prev++;
            d.push_front(*back);
            back--;
            
        }
        else if(back - prev == 1)
        {
            d.push_front(*prev);
            prev++;
            d.push_back(*prev);
            prev++;
        }
        else
        {
            d.push_front(*prev);
            prev++;
        }
    }
    
    int res_1 = cal_dis(d);
    
    prev = input.begin();
    back = input.end() - 1;
    
    deque<int> e;
    e.push_back(*prev);
    prev++;
    
    while(prev <= back)
    {
        if(back - prev >= 3)
        {
            e.push_front(*back);
            back--;
            e.push_back(*back);
            back--;
            e.push_front(*prev);
            prev++;
            e.push_back(*prev);
            prev++;
        }
        else if(back - prev == 2)
        {
            e.push_front(*back);
            back--;
            e.push_back(*back);
            back--;
            e.push_front(*prev);
            prev++;
            
        }
        else if(back - prev == 1)
        {
            e.push_front(*back);
            back--;
            e.push_back(*back);
            back--;
        }
        else
        {
            e.push_front(*back);
            back--;
        }
    }
    
    int res_2 = cal_dis(e);
    
    int res = res_1 > res_2 ? res_1 : res_2;
    
    return res;
    
}

int main()
{
    int n = 0;
    cin>>n;

    vector<int> input;
    
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    
    int res = get_max(input);
    
    cout<<res;
    
    return 0;
}

