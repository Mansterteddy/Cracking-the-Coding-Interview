//Explain what the following code does: ((n & (n - 1)) == 0)
#include <iostream>

//功能是用于判断n是不是2的整数幂，因为int是有符号数，因此这个功能只对于正数
//对于0而言，它和任何数与都为0，对于负数而言，最高位永远是1
//对于正数而言，如果是2的整数幂，则n和n-1每一位都相反，与后自然为0
#define judge(x) cout<<((x > 0) && ((x & (x - 1)) == 0))<<endl;

using namespace std;

int main()
{
    judge(4);
    judge(5);
    return 0;
}