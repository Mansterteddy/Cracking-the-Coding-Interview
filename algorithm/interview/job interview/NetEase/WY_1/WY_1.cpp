#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply_vector(vector<vector<int>> a, vector<int> b)
{
    int siz = b.size();
    vector<int> res(siz);

    for(int i = 0; i < siz; ++i)
    {   
        for(int j = 0; j < siz; ++j)
        {
            res[i] += a[i][j] * b[j]; 
        }
        res[i] = res[i] % 100;
    }

    return res;

}

vector<vector<int>> multiply_matrix(vector<vector<int>> a, vector<vector<int>> b)
{
    int siz = a.size();
    vector<vector<int>> res(siz);
    for(int i = 0; i < siz; ++i)
    {
        vector<int> res_son(siz);
        res[i] = res_son;
    }

    for(int i = 0; i < siz; ++i)
    {
        for(int j = 0; j < siz; ++j)
        {
            for(int k = 0; k < siz; ++k)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 100;
        }
    }

    return res;
}

vector<vector<int>> pow_matrix(vector<vector<int>> a, int n)
{
    if(n == 0)
    {
        int siz = a.size();
        vector<vector<int>> res(siz);
        for(int i = 0; i < siz; ++i)
        {
            vector<int> res_son(siz);
            res[i] = res_son;
        }
        for(int i = 0; i < siz; ++i)
        {
            for(int j = 0; j < siz; ++j)
            {
                if(i == j)
                    res[i][j] = 1;
            }
        }
        return res;
    }
    else if(n == 1)
    {
        return a;
    }
    else if(n % 2 == 0)
    {
        vector<vector<int>> res = pow_matrix(a, n / 2);
        return multiply_matrix(res, res);
    }
    else
    {
        vector<vector<int>> res = pow_matrix(a, n / 2);
        return multiply_matrix(multiply_matrix(res, res), a);
    }
}

int main()
{
    int n = 0;
    int k = 0;
    
    cin>>n;
    cin>>k;

    vector<int> v_1;

    int count = n;
    int input = 0;

    while(count > 0)
    {
        count--;
        cin>>input;
        v_1.push_back(input);
    }

    vector<vector<int>> base_m(n);
    for(int i = 0; i < n; ++i)
    {
        vector<int> base_m_son(n);
        base_m_son[i] = 1;

        if(i == n - 1)
        {
            base_m_son[0] = 1;
        }
        else
        {
            base_m_son[i+1] = 1;
        }

        base_m[i] = base_m_son;
    }

    vector<int> res = multiply_vector(pow_matrix(base_m, k), v_1);
    //vector<vector<int>> a = {{1, 1, 0}, {0, 1, 1}, {1, 0, 1}};
    //vector<int> b = {1, 2, 3};
    //vector<int> res = multiply_vector(pow_matrix(a, 3), b);

    for(int i = 0; i < res.size(); ++i)
    {
        if(i == res.size()-1) cout<<res[i];
        else cout<<res[i]<<" ";
    }

    return 0;
}