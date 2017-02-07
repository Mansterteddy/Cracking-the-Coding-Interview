/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
*/
#include <iostream>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) 
    {
        int len = str.length();
        int flag = 0;
        vector<int> x;

        if(len == 0) return 0;

        for(int i = 0; i < len; ++i)
        {
            if(str[i] == ' ')
            {
                if(x.size() == 0 && flag == 0) continue;
                else break;
            }

            if((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+') break;

            if(str[i] == '-' || str[i] == '+')
            {
                if(flag != 0) break;
                if(str[i] == '-') flag = -1;
                else flag = 1;
                if(x.size() != 0) break;
                else continue;
            }
            else x.push_back((int)str[i] - 48);
        }

        if(x.size() == 0) return 0;
        if(x.size() > 1)
        {
            while(x[0] == 0)
                x.erase(x.begin());
        }

        if(x.size() > 10)
        {
            if(flag == -1) return -2147483648;
            else return 2147483647;
        }

        if(x.size() == 10)
        {
            vector<int> max;
             int a = INT_MAX;
             while(a != 0)
             {
                 max.push_back(a%10);
                 a = a / 10;
             }
             if(flag == -1) max[0]++;
             for(int i = 0; i < 10; ++i)
             {
                 if(x[i] == max[9-i]) continue;
                 else{
                     if(x[i] < max[9 - i]) break;
                     else
                     {
                         if(flag == -1) return -2147483648;
                         else return 2147483647;
                     }
                 }
             }

        }

        int integer = 0;
        for(int i = 0; i < x.size(); ++i)
        {
            integer = integer * 10 + x[i];
        }
        if(flag == -1) integer = -integer;

        return integer;
    }
};

int main()
{
    Solution s;
    int ans = s.myAtoi("123");
    cout<<"ans: "<<ans<<endl;

    ans = s.myAtoi("abc");
    cout<<"ans: "<<ans<<endl;

    return 0;
}