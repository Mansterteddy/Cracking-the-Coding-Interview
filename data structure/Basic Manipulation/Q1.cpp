#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, p, q;
    cin>>p>>q>>n;

    int max_depth = 0;

    for(int i = 0; i < n; ++i)
    {
        double res = (100 - p / pow(2, i)) / q;
        int res_int = res;
        if(res_int >= res) max_depth += res_int + 1;
        else max_depth += res_int + 2;
    }

    


    return 0;
}