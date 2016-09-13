//Given a (decimal - e.g. 3.72) number that is passed in as a string,
//print the binary representation. If the number can not be represented accurately in binary, print "ERROR".
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//对于整数部分，不断除以2，暴露出来的余数部分，从低到高排列就是二进制，Y = X * 2 + Z 则Z就是最低位
//对于小数部分，不断乘以2，暴露出来的正数部分，从高到低排列就是二进制，0.75 = 0.5 + 0.25，即二进制0.11，0.75 * 2 即二进制左移一位 1.1 暴露出的1对应了0.5，以此类推

string print_binary(string val)
{
    int pos = val.find('.', 0);
    int intpart = atoi(val.substr(0, pos).c_str());
    cout<<"Int Part: "<<intpart<<endl;
    //?
    double decpart = atof(val.substr(pos, val.length()).c_str());
    cout<<"Decimal Part: "<<decpart<<endl;
    string intstr = "";
    string decstr = "";
    while(intpart > 0)
    {
        cout<<"Int part: "<<intpart<<endl;
        if(intpart & 1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart = intpart>>1;
    }
    while(decpart > 0)
    {
        cout<<"Decimal Part: "<<decpart<<endl;
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1)
        {
            decstr += "1";
            decpart -= 1;
        }
        else
        {
            decstr += "0";
        }
    }

    return intstr + "." + decstr;

}

int main()
{
    string a = "3.5";
    cout<<print_binary(a)<<endl;
    return 0;
}