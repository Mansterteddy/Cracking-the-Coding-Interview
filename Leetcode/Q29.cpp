//Divide two integers without using multiplication, division and mod operator. 
//It it is overflow, return MAX_INT. 

//Tag: int range 
#include <iostream>
#include <limits>

using namespace std;

class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            if(divisor == 0) return numeric_limits<int>::max();
            return 0;
        }
};

int main()
{
    Solution s;

    int res = s.divide(3, 1);
    cout<<"res: "<<res<<endl;

    return 0;
}