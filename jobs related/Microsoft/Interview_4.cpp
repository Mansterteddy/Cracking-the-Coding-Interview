/*
、给定一个数组，数组中没有相同的元素，求极大值，极大值指的是比两边都大。
这道题我首先问了一个很脑残的问题，是否一定会存在极值点，然后想了一下，最大值不就是极大值么？
所以这道题最简单的做法就是寻找最大值，O(n)的时间复杂度，但是，能否有更高效的算法呢？
注意这里我们要的是极大值，所以可以如此思考：假设我们有(a, b, c, d, e)这样一个数组，
我们直接找中间的元素，如果中间的元素比两边大，那么该元素就是极值点，
如果左边或者右边的元素比中间的元素大，那么我们就在对应一侧继续用相同的方式寻找极值点，
为什么这样的方式可以成立呢？假设d>c，那么我们有两种情况，d是右边一侧的最大值，
或者不是右边一侧的最大值，如果是第一种情况，则d是所求解，如果是第二种情况，则可以继续递归求解。
因此时间复杂度变为了O(logn)。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

    int findLocalMax(vector<int> v)
    {
        return iterative_find(v, 0, v.size()-1);
    }

    int iterative_find(vector<int>& v, int start, int end)
    {
        if(start == end) return v[start];

        if(end - start == 1)
        {
            if(v[start] > v[end]) return v[start];
            else return v[end];
        }

        int mid = (start + end) / 2;
        if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return v[mid];
        else if(v[start] > v[mid])
        {
            return iterative_find(v, start, mid-1);
        }
        else
        {
            return iterative_find(v, mid+1, end);
        }
    }
};

int main()
{
    vector<int> st = {1, 2, 3, 4, 5, 0};

    Solution s;
    int res = s.findLocalMax(st);
    cout<<"res: "<<res<<endl;

    return 0;
}