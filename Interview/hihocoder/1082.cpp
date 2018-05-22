/*
样例输入
The Marshtomp has seen it all before.
marshTomp is beaten by fjxmlhx!
AmarshtompB
样例输出
The fjxmlhx has seen it all before.
fjxmlhx is beaten by fjxmlhx!
AfjxmlhxB
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool test(string s, int index)
{
    int i = 1;
    string ma = "marshtomp";
    string ma1 = "MARSHTOMP";

    while(i <= 8)
    {
        if(s[index + i] != ma[i] && s[index + i] != ma1[i]) return false;
        i++; 
    }
    return true;
}

void replace(string& s, int index)
{
    string replace_str = "fjxmlhx  ";
    for(int i = 0; i < 9; ++i)
    {
        s[index + i] = replace_str[i];
    }
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<int> index_vec;
        for(int i = 0; i < s.length(); ++i)
        {
            if((s[i] == 'M' || s[i] == 'm') && (s.length() - i + 1 >= 9) )
            {
                bool flag = test(s, i);
                if(flag)
                {
                    index_vec.push_back(i);
                    replace(s, i);
                }       
            }
        }
        string::iterator str_iter = s.begin();
        for(int i = 0; i < index_vec.size(); ++i)
        {
            s.erase(str_iter + index_vec[i] + 7 - 2 * i, str_iter + index_vec[i] + 9 - 2 * i); 
        }
        cout<<s<<endl;
    }


    return 0;
}