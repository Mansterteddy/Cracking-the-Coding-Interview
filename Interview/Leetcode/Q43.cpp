//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2. 
//The length of both num1 and num2 is < 110
//Both num1 and num2 contains only digit 0-9
//Both num1 and num2 does not contain any leading zero. 
//You must not use any built-in BigInteger Liabrary or convert the inputs to integer directly 

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
    public:
        string multiply(string num1, string num2)
        {
            string res((num1.size() + 1) * (num2.size() + 1), '0');
            map<char, string> m1;

            //string s = multiply_val('0', "34");
            //cout<<"Print: "<<s<<endl;

            for(int i = num1.size() - 1; i >= 0; --i)
            {
                if(!m1.count(num1[i]))
                {
                    m1[num1[i]] = multiply_val(num1[i], num2);
                }
                string res_son = m1[num1[i]];
                for(int j = 0; j < num1.size() - 1 - i; ++j)
                {
                    res_son.insert(res_son.end(), '0');
                }
                cout<<"res_son: "<<res_son<<endl;
                add_val(res_son, res);
                cout<<"mid: "<<res<<endl;
            }

            int i = 0;
            while(true)
            {
                if(res[i] != '0')
                {
                    break;
                }
                else
                {
                    res.erase(res.begin());
                }
            }

            if(res.length() == 0) return "0";
            /*Istring val = multiply_val('0', "123");
            cout<<"val: "<<val<<endl;

            string s1 = "09999";
            string s2 = "9";
            add_val(s2, s1);
            cout<<"s1: "<<s1<<endl;*/

            return res;

        }

        void add_val(string s1, string& s2)
        {
            if(s1.length() == 0) return;
            string::iterator s1_it = s1.end() - 1;
            string::iterator s2_it = s2.end() - 1;

            int next = 0;
            while(true)
            {
                int a = *s1_it - 48;
                int b = *s2_it - 48;
                int sum = a + b + next;
                if(sum < 10)
                {
                    *s2_it = sum + 48;
                    next = 0;
                }
                else
                {
                    *s2_it = sum % 10 + 48;
                    next = sum / 10; 
                }

                if(s1_it == s1.begin()) break;

                s1_it--;
                s2_it--;
            }

            while(next == 1)
            {
                s2_it--;
                int sum = *s2_it + next - 48;
                if(sum < 10)
                {
                    *s2_it = sum + 48;
                    break;
                }
                else
                {
                    *s2_it = sum % 10 + 48;
                    next = sum / 10;
                }
            }
            
            return;

        }


        string multiply_val(char c1, string s1)
        {
            string res(s1.length() + 1, '0');
            for(int i = s1.length() - 1; i >= 0; --i)
            {
                int c1_i = (int)c1 - 48;
                int s1_i = (int)s1[i] - 48;
                int mul = c1_i * s1_i;
                //cout<<"c: "<<c1_i<<" s: "<<s1_i<<" mul: "<<mul<<endl;
                int cur = mul % 10;
                int next = 0;
                if(res[i+1] - 48 + cur >= 10)
                {
                    res[i+1] = res[i+1] - 48 + cur - 10 + 48;
                    next = 1;
                }
                else
                {
                    res[i+1] = res[i+1] - 48 + cur + 48;
                }

                res[i] = mul / 10 + next + 48; 
                
            }

            int i = 0;
            while(true)
            {
                if(res[i] != '0')
                {
                    break;
                }
                else
                {
                    res.erase(res.begin());
                }
            }

            return res;
        }

};

int main()
{
    Solution s;
    
    string num1 = "999";
    string num2 = "99999";
    string res = s.multiply(num1, num2);
    cout<<"Res: "<<res<<endl;

    return 0;
}