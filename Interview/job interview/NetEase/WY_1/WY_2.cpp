#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
    string input;
    int64_t n = 0;

    cin>>input;
    cin>>n;

    int64_t final_res = 0;
    vector<int> index;
    for(int i = 0; i < input.length(); ++i)
    {
        final_res *= 10;
        if(input[i] == 'X')
        {
            index.push_back(input.length() - 1 - i);
        }
        else
        {
            final_res += input[i] - '0'; 
        }
    }

    int residual = final_res % n;

    vector<vector<int64_t>> v1(index.size());

    for(int i = 0; i < v1.size(); ++i)
    {
        vector<int64_t> v1_son(n);
        v1[i] = v1_son;
    }

    for(int i = 0; i < v1.size(); ++i)
    {
        for(int k = 0; k < 10; ++k)
        {
            int64_t val = k * (int64_t)pow(10, index[i]) % n;
            if(i == 0)
            {
                v1[i][val] += 1;
            }
            else
            {      
                for(int j = 0; j < n; ++j)
                {
                    //cout<<"pass: "<<v1[i-1][j-val]<<" ";
                    if(j >= val) v1[i][j] += v1[i-1][j - val];
                    else v1[i][j] += v1[i-1][j + n - val];
                }
            }

            
        }
    }
    
    if(input == "3X8XXX99X04XXXXX7X")
    {
        cout<<"Ans: ";
        for(int i = 0; i < v1.size(); ++i)
        {
            for(int j = 0; j < v1[i].size(); ++j)
            {
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    if(residual == 0) cout<<v1[v1.size()-1][0];
    else cout<<v1[v1.size()-1][n-residual];

    return 0;

}

