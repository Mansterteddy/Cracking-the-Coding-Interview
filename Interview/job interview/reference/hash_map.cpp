#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;

    for(int i = 0; i < 26; ++i)
    {
        m[i] = 'A' + i;
    }

    map<char, int>::iterator iter;

    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        cout<<iter->first + 0<<" ";
        cout<<char(iter->second)<<endl;
    }

    return 0;
}