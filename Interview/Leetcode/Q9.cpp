//Determine whether an integer is a palindrome. Do this without extra space.
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        //if(x ==  -2147483648) return false;
        //if(x < 0) return isPalindrome(-x);
        if(x < 0) return false;
        if(x >= 0 && x < 10) return true;

        int count = 0;
        int y = x;
        while(y != 0)
        {
            count++;
            y = y / 10;
        }

        int w = x;
        int z = x;
        bool res = true;

        for(int i = 1; i <= count / 2; ++i)
        {
            int a = w % 10;
            w = w / 10;
            int div = pow(10, count - i);
            int b = z / div;
            z = z % div;
            
            if(a != b)
            {
                return false;
            }

        }

        return res;

    }
};

int main()
{
    Solution s;
    bool res = s.isPalindrome(2);
    cout<<"res: "<<res<<endl;

    res = s.isPalindrome(22);
    cout<<"res: "<<res<<endl;

    res = s.isPalindrome(232);
    cout<<"res: "<<res<<endl;

    res = s.isPalindrome(-232);
    cout<<"res: "<<res<<endl;

    res = s.isPalindrome(233);
    cout<<"res: "<<res<<endl;

    res = s.isPalindrome(24542);
    cout<<"res: "<<res<<endl;
    return 0;
}