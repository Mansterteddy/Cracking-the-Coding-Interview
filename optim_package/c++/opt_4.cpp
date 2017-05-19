//Using Newton Method

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    public:
        float update(float x, float target)
        {
            float pre_x = x;
            float derivative = 2 * pre_x;
            
            if(derivative <= 1e-5) return x;
            float pre_minus =  (pre_x * pre_x - target) / derivative;
            float new_x = pre_x - pre_minus;
            return new_x;
        }

        float mySqrt(float target)
        {
            float pre_x = 1;
            float pre_error = abs(pre_x * pre_x - target);
            float delta = 1e-5;

            while(true)
            {
                float new_x = update(pre_x, target);
                float new_error = abs(new_x * new_x - target);
                //cout<<"pre_error: "<<pre_error<<" new_error: "<<new_error<<" pre_x: "<<pre_x<<" new_x: "<<new_x<<endl;
                if(abs(pre_error - new_error) < delta) break;
                pre_x = new_x;
                pre_error = new_error;
            }

            return pre_x;
        
        }
};

int main()
{
    Solution s;

    float res = s.mySqrt(0);
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

    return 0;
}