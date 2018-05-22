/*
样例输入
5 1000
144 990
487 436
210 673
567 58
1056 897
样例输出
2099
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    
    cin>>n>>m;

    vector<int> value_vec;
    vector<int> cost_vec;
    
    for(int i = 0; i < n; ++i)
    {
        int need = 0;
        int value = 0;
        cin>>need>>value;
        value_vec.push_back(value);
        cost_vec.push_back(need);
    }
    
    vector<vector<int>> res_vec;
    
    for(int i = 0; i < n; ++i)
    {
        vector<int> res_vec_son(m+1, 0);
        
        if(i==0)
        {
            for(int j = 0; j < m + 1; ++j)
            {
                if(j < cost_vec[i]) res_vec_son[j] = 0; 
                else res_vec_son[j] = value_vec[i];
            }
        }
        
        res_vec.push_back(res_vec_son);
    }
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < m + 1; ++j)
        {
            if(j < cost_vec[i]) res_vec[i][j] = res_vec[i-1][j];
            else res_vec[i][j] = max(res_vec[i-1][j], res_vec[i-1][j-cost_vec[i]] + value_vec[i]);
        }
    }
    
    cout<<res_vec[n-1][m];
    
    return 0;
}

