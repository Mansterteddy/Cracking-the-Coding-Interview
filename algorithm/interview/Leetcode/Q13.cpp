//Given a roman numeral, convert it to an integer 
//Input is guaranteed to be within the range from 1 to 3999

//Tag：map
//这道题的关键在于 比如 I指代1 VI指代的是6 IV却指代的是4 因此区分优先级 遇到I时 先检测后面的元素是否是V 如果是的话 加的是4 而不是1
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    public:
        int romanToInt(string s)
        {
            map<string, int> vs;
            vs["I"] = 1; vs["IV"] = 4; vs["V"] = 5; vs["IX"] = 9; vs["X"] = 10; vs["XL"] = 40; vs["L"] = 50;
            vs["XC"] = 90; vs["C"] = 100; vs["CD"] = 400; vs["D"] = 500; vs["CM"] = 900; vs["M"] = 1000;
            vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            int res = 0;

            int index = 0;

            while(index < s.length())
            {
                if(index != s.length() - 1)
                {
                    string a;
                    a.push_back(s[index]);
                    a.push_back(s[index+1]);
                    if(vs.find(a) == vs.end())
                    {
                        string str_1;
                        str_1.push_back(s[index]);
                        res += vs[str_1];
                        index += 1;
                    } 
                    else
                    {
                        res += vs[a];
                        index += 2;
                    }
                }
                else
                {
                    string str_2;
                    str_2.push_back(s[index]);
                    res += vs[str_2];
                    break;
                }
            }

            return res;
        }
};

int main()
{
    Solution s;

    string str = "III";
    int num = s.romanToInt(str);
    cout<<"num: "<<num<<endl;

    str = "IV";
    num = s.romanToInt(str);
    cout<<"num: "<<num<<endl;


    str = "MLIV";
    num = s.romanToInt(str);
    cout<<"num: "<<num<<endl;

    return 0;
}