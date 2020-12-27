#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int left_num = 0;
    int right_num = 0;

    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')
        {
            left_num++;
        }
        else
        {
            right_num++;
        }
    }

    int out_1 = left_num > right_num : left_ num - right_num ? right_num

    return 0;     
}