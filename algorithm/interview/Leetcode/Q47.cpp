//Given a collection of numbers that might contain duplicates, return all possible unique permutations 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//注意：这里的vector<int> num，而不是引用。每次换了以后，在接下来的循环中，刚刚的数被换到前面，如果下一次循环，还和刚刚的数一样，那么就跳过。

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            /*cout<<"swap before";
            for(int w = 0; w < num.size(); ++w) cout<<num[w]<<" ";
            cout<<endl;*/
            swap(num[i], num[k]);
            /*cout<<"swap after";
            for(int w = 0; w < num.size(); ++w) cout<<num[w]<<" ";
            cout<<endl;*/
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};


class Solution1 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) 
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
    }

    void recursion(vector<int> &num, int i, int j, vector<vector<int>>& res)
    {
        if(i == j - 1)
        {
            res.push_back(num);
            return;
        }
        else
        {
            for(int k = i; k < j; ++k)
            {
                if(k != i && (num[k] == num[i] || num[k] == num[k-1])) continue;
                swap(num[k], num[i]);
                recursion(num, i + 1, j, res);
                swap(num[k], num[i]);
            }
        }
    }
};


int main()
{
    Solution s;

    //vector<int> nums = {-1, 2, 0, -1, 1, 0, 1};
    vector<int> nums = {1, 1, 2, 2};
    vector<vector<int>> res = s.permuteUnique(nums);

    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}