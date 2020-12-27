//Implement strStr()
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 

//Tag: Two Pointers
#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            int index = haystack.find(needle);
            if(index == string::npos)
            {
                return -1;
            }
            else
            {
                return index;
            }
        }
};

int main()
{
    Solution s;

    string s1 = "abcdef";
    string s2 = "def";
    int val = s.strStr(s1, s2);
    cout<<"Res: "<<val<<endl;

    return 0;
}