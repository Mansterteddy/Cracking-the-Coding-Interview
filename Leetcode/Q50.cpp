//Implement pow(x, n)

#include <iostream>

using namespace std;

class Solution
{
    public:
        double myPow(double x, int n)
        {
            double res = 0;
            if(n == 0) return 1;
            if(n == 1) return x;
            if(x < 0)
            {
                if(n % 2 == 0)
                {
                    return myPow(-x, n);
                }
                else
                {
                    return -myPow(-x, n);
                }
            }
            if(n < 0)
            {
                return 1.0 / myPow(x, -n);
            }
            if(n % 2 == 0)
            {
                res = myPow(x, n / 2);
                res = res * res;
            }
            else
            {
                res = myPow(x, n / 2);
                res = res * res * x;
            }

            return res;
        }
};

int main()
{
    Solution s;

    double res = s.myPow(34.00515, -3);
    cout<<"res: "<<res<<endl;

    return 0;
}