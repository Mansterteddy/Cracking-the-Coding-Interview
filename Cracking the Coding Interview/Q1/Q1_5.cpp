//Write a method to replace all spaces in a string with '%20'.

#include <iostream>

using namespace std;

//如果想要原地replace的话，通过第一遍遍历，确定要扩展多少空间 然后第二遍遍历 从后往前replace 因为如此replace是可以利用已知的字符串长度信息的
//在从后往前替换的过程中，新串用到的空间一定是旧串不需要的空间
void replace(char* a)
{
    int length = strlen(a);
    int cur = length;
    cout<<"Before Length: "<<length<<endl;
    for(int i = 0; i < cur; i++)
    {
        if (a[i] == ' ') length += 2;
    }
    cout<<"After Length: "<<length<<endl;
    
    a[length] = '\0';
    length -= 1;
    while(cur > 0)
    {
        if(a[cur - 1] != ' ')
        {
            a[length] = a[cur - 1];
            length--;
            cur--;
        }
        else
        {
            a[length] = '0';
            a[length - 1] = '2';
            a[length - 2] = '%';
            length -= 3;
            cur--;
        }        
    }
    
}

//开一个新的空间 保存替换的结果
char* replace_1(char *a)
{
    int length = strlen(a);
    int cur = length;
    for(int i = 0; i < cur; i++)
    {
        if(a[i] == ' ') length += 2;
    }
    cout<<"Before Length: "<<cur<<endl;
    cout<<"After Length: "<<length<<endl;
    
    char *aa = new char[length + 1];
    aa[length] = '\0';
    int anchor = 0;
    
    for(int i = 0; i < cur; i++)
    {
        if(a[i] != ' ')
        {
            aa[anchor] = a[i];
            anchor++;
        }
        else
        {
            aa[anchor] = '%';
            aa[anchor + 1] = '2';
            aa[anchor + 2] = '0';
            anchor += 3;
        }
    }
    
    return aa;
}

void replace_2(char *c)
{
    if(c == NULL) return;
    int len = strlen(c);
    
    if(len == 0) return;
    int cnt =0;
    for(int i = 0; i < len; i++)
    {
        if(c[i] == ' ') ++cnt;
    }
    
    int p = len +  2 * cnt;
    
    c[p--] = '\0';
    
    for(int i = len -1; i >= 0; --i)
    {
        if(c[i] == ' ')
        {
            c[p] = '0';
            c[p - 1] = '2';
            c[p - 2] = '%';
            p -= 3;
        }
        else
        {
            c[p] = c[i];
            --p;    
        }
    }
}
int main()
{
    char a[] = "I am Zhang Yuan ";
    //replace(a);
    char *aa = replace_1(a);
    cout<<"Replaced_1: "<<aa<<endl;
    replace_2(a);
    cout<<"Replaced: "<<a<<endl;
    return 1;
}
