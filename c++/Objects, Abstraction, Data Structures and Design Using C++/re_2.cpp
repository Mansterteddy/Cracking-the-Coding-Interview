#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
    char a = s1[0];
    char b = s2[0];
    return (a < b);
}

int main()
{
    int N;
    cin>>N;
    string* s1 = new string[N];
    string* s2 = new string[N];

    for(int a0 = 0; a0 < N; a0++)
    {
        string firstName;
        string emailID;
        cin>>firstName>>emailID;
        s1[a0] = firstName;
        s2[a0] = emailID;
    }

    vector<string> pre;
    
    for(int i = 0; i < N; i++)
    {
        char *pch;
        char *data;
        int len = s2[i].length();
        data = (char*)malloc((len + 1) * sizeof(char));
        s2[i].copy(data, len, 0);
        data[len] = '\0';
       
        char* pch1 = strtok(data, "@");
        char* pch2 = strtok(NULL, "@");
        char* pch2_2 = "gmail.com";
        if(!strcmp(pch2, pch2_2))
        {
            pre.push_back(pch1);
        }
    }

    string *fina = new string[pre.size()];
    for(int i = 0; i < pre.size(); i++)
    {
        fina[i] = pre[i];
    }

    sort(fina, fina + pre.size(), cmp);
    for(int i = 0; i < pre.size(); i++)
    {
        cout<<fina[i]<<endl;
    }
    return 0;
}


