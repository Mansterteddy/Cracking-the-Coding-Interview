//Divide two integers without using multiplication, division and mod operator. 
//It it is overflow, return MAX_INT. 

//Tag: int range, bit operation
//想要快速得到结果，就只能考虑位运算。
//被除数减去一次除数，结果+1
//被除数减去二次除数，结果+2
//被除数减去三次除数，结果+3
#include <iostream>
#include <limits>

using namespace std;

class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            if(divisor == 1) return dividend;

            long long a = abs((double)dividend);
            long long b = abs((double)divisor);
            long long res = 0;
            while(a >= b)
            {
                long long c = b;
                for(int i = 0; a >= c; i++, c <<= 1)
                {
                    a -= c;
                    res += 1<<i;
                }
            }

            if(res == 0x80000000) return 2147483647;
            else return ((dividend ^ divisor) >> 31) ? (-res): (res);
        }
};

int main()
{
    Solution s;

    int res = s.divide(10, 3);
    cout<<"res: "<<res<<endl;

    return 0;
}