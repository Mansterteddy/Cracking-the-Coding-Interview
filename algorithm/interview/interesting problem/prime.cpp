//一般来讲，判断一个数n是不是质数，就是判断从1到n-1，能否除了1，还存在其他数可以整除它
//n = a * b = \sqrt{n} * \sqrt{n}
//所以判断从1到sqrt(n)中是否存在整除数就足够了，此时的时间复杂度是O(logn)
//但是如果n非常大时，\sqrt(n)也很大，这样也很慢。
//开一个bool数组，然后从2开始，到sqrt(n)结束，2是质数，那么2的倍数全是合数，全标记好
//3是质数，然后3的倍数全是合数，以此类推，最后看bool数组中谁没被标记，谁就是质数，这样可以避免很多重复操作

#include <iostream>
#include <cmath>
using namespace std;

void prime(int n)
{
    if(n == 1)
    {
        cout<<"Not prime"<<endl;
        return;
    }
    bool flag = false;
    int sqrt_n = sqrt(n);
    for(int i = 2; i <= sqrt_n; i++)
    {
        if(n % i == 0)
        {
            flag = true;
            break;
        }
    } 
    if(flag == true)
    {
        cout<<"Not prime"<<endl;
    }
    else
    {
        cout<<"Prime"<<endl;
    }
}

int main()
{
    int n = 6;
    prime(n);
    return  0;
}