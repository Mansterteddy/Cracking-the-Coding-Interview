/*
有一个从1到n的数列，按照字典序排列，第k个数字是多少？
首先处理n，确定它有几位，每一位的数字是多少，使用一个数组将其保存起来。
随后从1开始处理，1、10、11、...、100、101、...、2、20、21、...、200...
对应的数据范围为1，1+10，1+10+100，...
注意对n最高位的特殊处理，判断k是否在此范围内即可。
举例：
n=16 k=7
1 10 11 12 13 14 15 16 2 3 4 5 6 7 8 9
res = 15
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    cout << "Input n:" << endl;
    int n = 0;
    cin >> n;

    cout << "Input k:" << endl;
    int k = 0;
    cin >> k;
    
    if(k > n)
    {
        cout << "Null!" << endl;
        return 0;
    }

    int m = n;
    vector<int> range;
    
    while(m!=0)
    {
        if(m >= 10) range.push_back(m%10);
        else range.push_back(m);
        m = m / 10;
    }

    int res = 0;
    int index = 0;
    int pre_index = index;

    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 0; j < range.size(); ++j)
        {
            pre_index = index;
            if(j==range.size()-1 && i > range[j])
            {
                break;
            }
            if(j==range.size()-1 && i==range[j])
            {
                index += n - pow(10,j) + 1;
            }
            else
            {
                index += pow(10, j);
            }

            if(index >= k)
            {
                res = (k - pre_index - 1) + i * pow(10, j);
                cout << res << endl;
                return res;
            }
        }
    }

    return 0;
}