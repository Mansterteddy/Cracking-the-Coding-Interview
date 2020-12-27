//Using Newton Method

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    public:
        int update(int x, int target)
        {
            float pre_x = x;
            float derivative = 2 * pre_x;
            
            if(derivative == 0) return x;
            float pre_minus =  (pre_x * pre_x - target) / derivative;
            int new_x = pre_x - pre_minus;
            return new_x;
        }

        int mySqrt(int target)
        {
            long long pre_x = target;
            long long pre_error = abs(pre_x * pre_x - target);

            while(true)
            {
                long long new_x = update(pre_x, target);
                long long new_error = abs(new_x * new_x - target);
                cout<<"pre_error: "<<pre_error<<" new_error: "<<new_error<<" pre_x: "<<pre_x<<" new_x: "<<new_x<<endl;
                if(pre_error < new_error || pre_x == new_x) break;
                pre_x = new_x;
                pre_error = new_error;
            }

            return pre_x * pre_x > target ? pre_x - 1 : pre_x;
        
        }
};

int main()
{
    Solution s;

    int res = s.mySqrt(0);
    cout<<"res: "<<res<<endl;
    
    res = s.mySqrt(1);
    cout<<"res: "<<res<<endl;
    
    res = s.mySqrt(2);
    cout<<"res: "<<res<<endl;

    res = s.mySqrt(3);
    cout<<"res: "<<res<<endl;

    res = s.mySqrt(4);
    cout<<"res: "<<res<<endl;

    res = s.mySqrt(7);
    cout<<"res: "<<res<<endl;

    res = s.mySqrt(2147395599);
    cout<<"res: "<<res<<endl;
    return 0;
}