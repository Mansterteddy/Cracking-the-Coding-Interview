/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) 
    {
        string res;
        vector<vector<char>> rows(numRows);
        
        if(numRows == 1) return s;

        for(int i = 0; i < s.length(); ++i)
        {
            int mod = 2 * numRows - 2;
            int res = i % mod;
            if(res < numRows)
            {
                rows[res].push_back(s[i]);
            }
            else
            {
                int r = (numRows - 1) - (res - (numRows - 1));
                rows[r].push_back(s[i]);
            }
        }

        for(int i = 0; i < numRows; ++i)
        {
            for(int j = 0; j < rows[i].size(); ++j)
            {
                res += string(1, rows[i][j]);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    string res = s.convert("PAYPALISHIRING", 3);
    cout<<"res: "<<res<<endl;
    return 0;
}