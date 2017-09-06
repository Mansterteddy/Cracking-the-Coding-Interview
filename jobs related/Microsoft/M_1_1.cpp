/*
这道题建议画一下图，看起来像个深搜，实则不是，可以reduce到一个很简单的形式。
通过分析，我们可以知道。第一个关卡次数的概率和第二个关卡次数的概率完全无关，进一步分析，
我们可以得到如下性质：
E = E[1] + E[2] + ...
也就是说，最后要求的期望，等于每一个关卡的期望次数之和，直观上，这件事情也成立。
概率中所有的问题都是加减乘除问题，所以只需要画图，计算，注意下性质就可以了，独立事件一定要认真分析！
当然，透过对问题的观察，我们可以将这个算法的时间复杂度降到O(1)，由于每次都会除以2，
因此就算P=100，在8次以后，也会降到0%，也就是说，
无论P是多少，大于等于8的次数以后，期望是相同的。
*/

#include <iostream>
#include <cstdio>

using namespace std;

int p, q, n;

double get_item(int i)
{
    int pi = i < 7 ? p / (1 << i): 0;

    double tmp = 1;
    double E = 0;

    for(int j = 0; j <= 100; ++j)
    {
        E += tmp * (j + 1) * pi * 0.01;
        if(pi == 100) return E;
        tmp *= 1 - pi * 0.01;
        pi += q;
        if(pi >= 100) pi = 100;
    }

    return E;
}

int main()
{
    double ans = 0;
    cin>>p>>q>>n;

    int iter = (n > 8) ? 8 : n;

    for(int i = 0; i < iter; ++i)
    {
        ans += get_item(i);
    }

    if(iter == 8) ans += get_item(8) * (n-8);
    printf("%.2lf\n", ans);
    return 0;
}