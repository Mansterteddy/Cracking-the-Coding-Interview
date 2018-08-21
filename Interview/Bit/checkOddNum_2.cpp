/*
给定一组数字，这些数字里面每一个都出现了三次，只有一个数字出现了一次，要求在O(n)时间，O(1)空间内求解。
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void ParseNum(vector<int>& digit, int value)
{
    for(int i = 0; i < 32; ++i)
    {
        int residual = value % 2;
        digit[i] += residual;
        value = value / 2;
    }
}

int main()
{
    vector<int> input = {1, 1, 1, 3, 3, 3, 4, 4, 4, 5, 5, 5, 0};
    vector<int> digit(32, 0);

    for(vector<int>::iterator iter = input.begin(); iter < input.end(); ++iter)
    {
        int val = *iter;
        ParseNum(digit, val);
    }

    int res = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(digit[i] % 3 != 0) res += pow(2, i);
    }

    cout << res << endl;

    return 0;
}