#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void recursive(int& res, vector<int> v_1, int index, int final_val, int delim, int count)
{
    if(index == v_1.size() - 1)
    {
        for(int i = 0; i < 10; ++i)
        {
            int final_res = final_val + i * pow(10, v_1[count - 1 - v_1[index]]);
            if(final_res % delim == 0) res += 1;
        }
        return;
    }
    else
    {
        for(int i = 0; i < 10; ++i)
        {
            int final_res = final_val + i * pow(10, v_1[count - 1 - v_1[index]]);
            recursive(res, v_1, index + 1, final_res, delim, count);
        }
    }
}

int main()
{
    char c1[18];
    long n = 0;

    cin>>c1;
    cin>>n;

    vector<long> v_1;

    long final_val = 0;
    long count = 0;

    for(int i = 0; c1[i] != '\0'; ++i)
    {
        count++;
        if(c1[i] == 'X')
        {
            v_1.push_back(i);
        }
        else
        {
            final_val += c1[i] - 48;
            final_val *= 10;
        }
    }


    long final_val_1 = 0;

    for(int i = 0; c1[i] != '\0'; ++i)
    {
        final_val_1 *= 10;
        if(c1[i] == 'X')
        {
            final_val_1 += 9;
            //v_1.push_back(i);
        }
        else
        {
            final_val_1 += c1[i] - 48;
        }
        
    }

    while(final_val % n != 0)
    {
        final_val++;
    }

    while(final_val_1 % n != 0)
    {
        final_val_1--;
    }


    cout<<final_val<<" "<<final_val_1<<endl;
    
    long res = (final_val_1 - final_val) / n + 1;

    //recursive(res, v_1, 0, final_val, n, count);

    cout<<res<<endl;

    return 0;
}