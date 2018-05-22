//Given an integer, convert it to a roman numeral
//Input is guaranteed to be within the range from 1 to 3999. 

//Tag: 十进制表示
//这道题提醒我 不要总是用那么多if 考虑各种情况 而应该考虑简化问题，比如2999，先和1000比较，得到1999，继续和1000比较，得到999，继续和1000比较，如果比1000小，则和900比较，这样循环下去。
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
    public:
        string intToRoman(int num)
        {
            //1: I 4: IV 5: V 9: IX 10: X 40: XL 50: L 90: XC 100: C 400: CD 500: D 900: CM 1000: M
            map<int, string> vs;
            vs[1] = "I"; vs[4] ="IV"; vs[5] = "V"; vs[9] = "IX"; vs[10] = "X"; vs[40] = "XL"; vs[50] = "L";
            vs[90] = "XC"; vs[100] = "C"; vs[400] = "CD"; vs[500] = "D"; vs[900] = "CM"; vs[1000] = "M"; 
            vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            int index = 0;
            string str = "";

            while(num != 0)
            {
                if(num >= value[index])
                {
                    str += vs[value[index]];
                    num -= value[index];
                }
                else
                {
                    index++;
                }
            }

            return str;
        }
};

int main()
{
    Solution s;

    int num = 100;
    string str = s.intToRoman(num);
    cout<<"str: "<<str<<endl;

    num = 2;
    str = s.intToRoman(num);
    cout<<"str: "<<str<<endl;

    return 0;
}