//Given an array of non-negative integers, you are initially positioned at the first index of the array. 
//Each element in the array represents your maximum jump length at that position
//Your goal is to reach the last index in the minimum number of jumps 

//这个题的贪心性质在于：从某个节点的下一点开始，到这个节点所能达到的范围内，所需的步数都为到这个节点的步数+1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int jump(vector<int>& nums)
        {
            int result = 0;
            int last = 0;
            int cur = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(i > last)
                {
                    last = cur;
                    ++result;
                }
                cur = max(cur, nums[i] + i);
                cout<<"cur: "<<cur<<endl;
            }

            return result;
        }
};

class Solution1
{
    public:
        int jump(vector<int>& nums)
        {
            vector<int> res_vec(nums.size());
            for(int i = 0; i < nums.size(); ++i)
            {
                if(i == 0) res_vec[i] = 0;
                else
                {
                    int min = i;
                    for(int j = i - 1; j >= 0; --j)
                    {
                        if(j + nums[j] >= i && res_vec[j] + 1 < min)
                        {
                            min = res_vec[j] + 1;
                        }
                    }
                    res_vec[i] = min;
                }

            }

            return *(res_vec.end()-1);   
        }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution s;

    int res = s.jump(nums);

    cout<<"Res: "<<res<<endl;

    return 0;
}