#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //BGGBBB
    string s;
    cin>>s;

    string s1 = s;
    string s2 = s;

    int val_1 = 0;
    int val_2 = 0;

    for(int i = s1.length() - 1; i >= 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(s1[j] == 'G' && s1[j+1] == 'B')
            {
                swap(s1[j], s1[j+1]);
                val_1++;
            }
        }
    }
    //cout<<"s1: "<<s1<<endl;

    for(int i = s2.length() - 1; i >= 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(s2[j] == 'B' && s2[j+1] == 'G')
            {
                swap(s2[j], s2[j+1]);
                val_2++;
            }
        }
    }
    //cout<<"s2: "<<s2<<endl;

    cout<<(val_1 > val_2 ? val_2: val_1)<<endl;
    return 0;
}