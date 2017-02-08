/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. 
*/
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int res = INT_MIN;

        int first = 0;
        int second = height.size() - 1;

        while(first < second)
        {
            int area = (second - first) * min(height[first], height[second]);
            if(area > res) res = area;

            (height[first] > height[second]) ? second-- : first++;

        }

        return res;         

    }
};

int main()
{
    Solution s;

    vector<int> height = {1, 2, 3, 4};
    int ans = s.maxArea(height);
    cout<<"ans: "<<ans<<endl;

    height = {1, 3, 3, 4};
    ans = s.maxArea(height);
    cout<<"ans: "<<ans<<endl;

    return 0;
}