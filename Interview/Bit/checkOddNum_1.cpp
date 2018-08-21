/*
给定一组数字，这些数字里面每一个都出现了两次，只有一个数字出现了一次，要求在O(n)时间，O(1)空间内求解。
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {10, 2, 3, 2, 3, 10, 1, 1, 4};

    int res = v[0];
    for(int i = 1; i < v.size(); ++i)
    {
        res = res ^ v[i];
    }

    cout << "res: " << res <<endl;

    return 0;
}