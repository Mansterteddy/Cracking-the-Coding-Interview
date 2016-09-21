//Write a method that returns all subsets of a set
#include <iostream>
#include <vector>
using namespace std;

//列举01组合，0不放入数，1放入数，这样就可以列举完毕
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi get_subsets(int a[], int n)
{
    vvi subsets;
    //总共列举情况的数目
    int max = 1<<n;
    for(int i = 0; i < max; i++)
    {
        vi subset;
        int idx = 0;
        int j = i;
        while(j > 0)
        {
            if (j & 1)
            {
                subset.push_back(a[idx]);
            }
            j >>= 1;
            ++idx;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

void print_vi(vi i)
{
    vector<int>::iterator iter;
    for(iter = i.begin(); iter != i.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
}

vvi get_subset1(int a[], int idx, int n)
{
    vvi subsets;
    if(idx == n)
    {
        vi subset;
        subsets.push_back(subset);
    }
    else
    {
        vvi rsubsets = get_subset1(a, idx + 1, n);
        int v = a[idx];
        for(int i = 0; i < rsubsets.size(); i++)
        {
            vi subset = rsubsets[i];
            subsets.push_back(subset);
            subset.push_back(v);
            subsets.push_back(subset);
        }
    }

    return subsets;
}
//int a[9]; int a[] = {1, 2, 3};声明的是静态数组
//int *d = nenw int[9];声明的就是动态数组
//静态数组可以使用sizeof()计算大小，而动态数组不行。
int main()
{
    int a[] = {1, 2, 3};
    int size = sizeof(a) / sizeof(a[0]);
    vvi v_1 = get_subsets(a, size);
    
    vector<vector<int>>::iterator iter;
    for(iter = v_1.begin(); iter != v_1.end(); iter++)
    {
        print_vi(*iter);
    }

    vvi v_2 = get_subset1(a, 0, size);

    vector<vector<int>>::iterator iter_1;
    for(iter_1 = v_2.begin(); iter_1 != v_2.end(); iter_1++)
    {
        print_vi(*iter_1);
    }

    return 0;
}