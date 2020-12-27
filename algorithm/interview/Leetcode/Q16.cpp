//Tag: Greedy

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {
            sort(nums.begin(), nums.end());

            int min = INT_MAX;
            int res = INT_MAX;

            for(int i = 0; i < nums.size() - 2; ++i)
            {
                
                int j = i + 1;
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int k = nums.size() - 1;

                while(j < k)
                {
                    int diff = abs(target - nums[i] - nums[j] - nums[k]);
                    if(diff < min) 
                    {
                        min = diff;
                        res = nums[i] + nums[j] + nums[k];
                    }

                    if(nums[i] + nums[j] + nums[k] < target)
                    {
                        ++j;
                        while(nums[j] == nums[j - 1] && j < k)
                        {
                            ++j;
                        }
                    }
                    else if(nums[i] + nums[j] + nums[k] > target)
                    {
                        --k;
                        while(nums[k] == nums[k + 1] && j < k)
                        {
                            --k;
                        }
                    }
                    else
                    {
                        return target;
                    }
                }
            }
            return res;
        }
};

int main()
{
    Solution s;

    vector<int> vc = {0, 1, 2};
    int res = s.threeSumClosest(vc, 3);
    cout<<"res: "<<res<<endl;
    return 0;
}