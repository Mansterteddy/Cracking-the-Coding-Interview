//Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, 
//write code to check if s2 is a rotation of s1 using only one call to isSubstring (i.e., "waterbottle" is a rotation of "erbottlewat")
#include <iostream>
#include <string>

using namespace std;

//想要调用一次函数 就可以判断结果 就不能每次都旋转一位 然后对比两个字符串
//观察问题 可以了解到 旋转的子串 一定会满足连贯的特性 集对于waterbottlewaterbottle这样的字符串 waterbottle的旋转字符串会使得对应数组里出现连续的1
bool isSubstring(char *a, char *b)
{
    int length = strlen(a);
    char *c = new char[length * 2];
    for(int i = 0; i < length * 2; i++)
    {
        if(i < length)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = a[i - length];   
        } 
    }
    cout<<"c: "<<c<<endl;
    
    int count = 0;
    
    for(int i = 0; i < length * 2; i++)
    {
        if(c[i] == b[0])
        {
            cout<<"Point: "<<c[i]<<endl;
            for(int j = 0; j < length; j++)
            {
                count++;
                cout<<"Char:"<<b[j]<<" "<<c[i + j]<<"Count:"<<count<<endl;
                if(i + j >= 2 * length) return false;
                if(c[i + j] != b[j])
                {
                     break;
                }
            }
            if(count == length) return true;
            count = 0;
        }
    }
    
    return false;
}

bool isSubstring_1(string s1, string s2)
{
    if(s1.find(s2) != string::npos) return true;
    else return false;
}

bool isRotation(string s1, string s2)
{
    if(s1.length() != s2.length() || s1.length() <= 0)
    {
        return false;
    }
    return isSubstring_1(s1 + s2, s2);
}


int main()
{
    char *a = "waterbottle";
    char *b = "erbottlewet";
    
    bool flag = isSubstring(a, b);
    cout<<"is rotated:"<<flag<<endl;
    return 1;
}