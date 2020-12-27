//Given an unsorted integer array, find the first missing positive integer

//Tag: Sort

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//此方法首先找到最大值 找到最小值 然后申请一个数组 进行占位 找到第一个为0的位置 在这个过程中，可以将每个int转换为一个8位二进制数，进一步节省空间。
class Solution2
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {
            vector<int>::iterator it;
            int min = -1;
            int max = -1;
            bool test_flag = false;

            for(it = nums.begin(); it != nums.end(); it++)
            {
                if(!test_flag && *it > 0)
                {
                    min = *it;
                    max = *it;
                    test_flag = true;
                }
                if(*it > 0 && test_flag)
                {
                    if(*it < min) min = *it;
                    if(*it > max) max = *it;
                }
            }

            if(max <= 0) return 1;
            if(min > 1) return 1;
            if(max == min)
            {
                if(max == 1) return 2;
                else return 1;
            }

            int arr_size = (max - min) / 32 + 1;
            int remainder = (max - min) % 32;
            //cout<<"arr_size: "<<arr_size<<" "<<remainder<<endl;
            int* arr = new int [arr_size];
            memset(arr, 0, sizeof(int) * arr_size);

            //cout<<"Start: "<<arr[0]<<endl;

            for(it = nums.begin(); it != nums.end(); it++)
            {
                if(*it > 0)
                {
                    int d1 = (*it - min) / 32;
                    int d2 = (*it - min) % 32;
                    int d3 = 1<<d2;
                    arr[d1] = arr[d1] | d3;
                    //cout<<"hehe "<<d1<<" "<<d2<<" "<<d3<<" "<<arr[d1]<<endl;

                }
            }
            
            int res = -1;

            for(int i = 0; i < arr_size; i++)
            {
                if( i!= arr_size - 1 && arr[i] != 2^32 - 1)
                {
                    res = i;
                    break;
                }
                else if(i == arr_size - 1 && arr[i] != pow(2, remainder) - 1)
                {
                    res = i;
                    break;
                }
            }
            //cout<<"res: "<<res<<endl;

            if(res == -1) return max + 1;
            else
            {
                int dat = arr[res];
                int count = 0;
                while(true)
                {
                    int rem = dat & 1;
                  //  cout<<"rem: "<<rem<<endl;
                    if(rem == 0)
                    {
                        return min + 32 * res + count; 
                    }
                    count++;
                    dat = dat>>1;
                }
            }

        }
};

//此方法更trick一些，也是一种有趣的排序方法，遍历数组中的每一个元素，将元素交换到对应位置上去，如果对应元素超出数组大小，则不变。最终，数组对应位置的元素和index不相等的位置，就是第一个缺失的正整数。
//当然交换后，不能直接遍历下一个位置，因为交换来的元素可能是一个新元素，需要继续进行交换，直到不再交换。
class Solution
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {
            int temp;
            int curElem;
            int i = 0;

            while(i < nums.size())
            {
                curElem = nums[i];
                //不在范围内的元素 重复的元素 不交换
                if(curElem > 0 && curElem <= nums.size() && curElem != nums[curElem - 1])
                {
                    temp = nums[curElem - 1];
                    nums[curElem - 1] = nums[i];
                    nums[i] = temp;
                }
                //交换过来的新元素 在nums[i]位置 仍然需要处理
                else i++;
            }

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] != (i + 1))
                    return i + 1; 
            }

            return nums.size() + 1;
        }

};

int main()
{
    Solution s1;
    vector<int> v1 = {-3, 0, 1};
    int res = s1.firstMissingPositive(v1);
    cout<<res<<endl;

    /*
    v1 = {-3, 0, -1};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;

    v1 = {1, 2, 3};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;

    v1 = {1, 4, 3};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;

    v1 = {0, -1, 3, 1};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;

    v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;*/

    v1 = {39,8,43,12,38,11,-9,12,34,20,44,32,10,22,38,9,45,26,-4,2,1,3,3,20,38,17,20,25,41,35,37,18,37,34,24,29,39,9,36,28,23,18,-2,28,34,30};
    res = s1.firstMissingPositive(v1);
    cout<<res<<endl;
    return 0;
}