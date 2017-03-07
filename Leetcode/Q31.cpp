//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
//If such arrangement is not possible, it must rearrange it as the lowest possible order(i.e., sorted in ascending order)
//The replacement must be in-place, do not allocate extra memory. 

//Tag: sort
#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
    public:

        void nextPermutation(vector<int>& nums)
        {
            int val;
            int val_cor;
            bool flag = true;
            int cur = nums.size() - 1;

            while(true)
            {
                int first = nums[cur];
                for(int i = cur - 1; i >= 0; i--)
                {
                    if(nums[i] < first)
                    {
                        val = i;
                        val_cor = cur;
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                {
                   if(cur > 0) cur--;
                   else break;
                }
                else break;
            }

            if(flag)
            {
                cout<<"Flag"<<endl;
                sort(nums.begin(), nums.end());
                return;
            }

            int index = cur - 1;
            while(index > val + 1)
            {
                int second = nums[index];
                for(int i = index - 1; i >= val + 1; i--)
                {
                    if(nums[i] < second) 
                    {
                        if(i > val) 
                        {
                            val = i;
                            val_cor = index;
                        }
                        break;
                    }
                }

                index--;
            }

            int temp = nums[val_cor];
            nums[val_cor] = nums[val];
            nums[val] = temp;
            cout<<"min: "<<val<<" val_cor: "<<val_cor<<endl;
            sort(nums.begin() + val + 1, nums.end());
        }

};

int main()
{
    Solution s;

    vector<int> nums = {1, 2, 3, 9, 8, 7, 6, 3, 4, 0};

    s.nextPermutation(nums);

    cout<<"Res: "<<endl;

    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<endl;
    }

    nums = {4,2,0,2,3,2,0};

    s.nextPermutation(nums);

    cout<<"Res: "<<endl;

    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<endl;
    }

    nums = {2, 2, 7, 5, 4, 3, 2, 2, 1};

    s.nextPermutation(nums);

    cout<<"Res: "<<endl;

    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<endl;
    }


    return 0;
}