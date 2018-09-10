//N!的末尾能有多少0，找到最小的N，比如5！末尾有一个0，10！末尾有2个0
//这个题基于两个发现：1、最后一位是0，是由于有10相乘；2、有10相乘是因为存在5和2，而在阶乘中，2永远比5多，因此有多少个5的倍数，就存在相对应的0。

#include <iostream>
#include <cmath>

using namespace std;

int val(int value)
{
    int res = 0;
    if(value == 0) return 1;
    if(value % 5 != 0) return 1;
    else
    {
        res += 1 + val(value / 5);
    }
    return res;
}

int tsn(int num_zero)
{
    int value = 0;
    int count = 0;
    while(value != num_zero)
    {
        count++;
        if(value > num_zero)
        {
            cout<<"No Solution!"<<endl;
            return 0;
        }
        value += val(count);
    }
    cout<<"Count: "<<count<<endl;
    return count;
}

//5!为1个0 10!为2个0
//10可以因式分解为5和2，而5永远比2少，因此有多少个5，就有多少个0
//5：1 10：2 15：3 20：4 25：6 30：7 35：8 40：9 45：10 50：12 
//log换底
int main(int argc, char** argv)
{

    //int res = val(100);
    int res = tsn(31);
    cout<<"Res: "<<res * 5<<endl;
    return 0;
}