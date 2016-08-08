//Write a method to decide if two strings are anagrams or not.判断两个字符串是否是变位词
//变位词指的是组成两个单词的字符相同，但是位置不同的单词，比如abbcd和abcdb就是一对变位词。
#include <iostream>

using namespace std;

//下面的方法是O(n)的,但是需要开一个较大空间的数组，还有一种先排序后一个一个比较的方法是O(nlogn)
int anagrams(char *a, char *b)
{
    int c[256];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < strlen(a); i++)
    {
        c[int(a[i])]++;
    }
    for(int j = 0; j < strlen(b); j++)
    {
        c[int(b[j])]--;
    }
    //为了获得一个其他类型数组的大小 需要使用sizeof(c) / sizeof(c[0]) 这种形式
    cout<<"size of c:"<<sizeof(c)<<endl;
    for(int k = 0; k < sizeof(c) / sizeof(c[0]); k++)
    {
        if(c[k] != 0) return 0;
    }
    return 1;
    
}

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        cout<<"Not enough parameters!"<<endl;
        return 0;
    }
    char *a = argv[1];
    char *b = argv[2];
    //char *转换成char数组 要么 for循环 一个一个赋值 要么strcpy
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"Judge Answer: "<<anagrams(a, b)<<endl;
    return 1;
}