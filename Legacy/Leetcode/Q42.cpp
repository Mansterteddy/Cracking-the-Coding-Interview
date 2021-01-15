//Given n non-negative integers representing an elevation map where the width of each bars is 1, compute how much water
//it is able to trap after raining. 
//For example, Given [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] return 6. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int trap(vector<int>& height)
        {
            int res = 0;

            if(height.size() == 0) return res;
            
            vector<int> forward(height.size());
            vector<int> backward(height.size());

            int max_f = height[0];
            int max_b = *(height.end()-1);

            for(int i = 0; i < height.size(); ++i)
            {
                if(max_f > height[i])
                {
                    forward[i] = max_f;
                }
                else
                {
                    max_f = height[i];
                    forward[i] = height[i];
                }

                if(max_b > height[height.size() - 1 - i] )
                {
                    backward[height.size() - 1 - i] = max_b;
                }
                else
                {
                    max_b = height[height.size() - 1 - i];
                    backward[height.size() - 1 - i] = height[height.size() - 1 - i]; 
                }
            }


            for(int i = 0; i < height.size(); ++i)
            {
                cout<<forward[i]<<" ";
            }
            cout<<endl;

            for(int i = 0; i < height.size(); ++i)
            {
                cout<<backward[i]<<" ";
            }

            for(int i = 0; i < height.size(); ++i)
            {
                int min_val = (forward[i] < backward[i]) ? forward[i] : backward[i];
                if(height[i] < min_val)
                {
                    res += min_val - height[i];
                }
            }

            return res;
        }
};

int main()
{
    Solution s;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int res = s.trap(height);
    cout<<"res: "<<res<<endl;

    return 0;
}