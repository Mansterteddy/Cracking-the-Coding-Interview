//Implement an algorithm to determine if a string has all unique characters. 
//What if you can not use additional data structures?
#include<iostream>

using namespace std;

//以字符串形式出现的，编译器会在结尾自动添加\0，只有字符数组才有'\0'的概念
//char a1[100]; 在栈上分配
//char* pa = new char[100];在堆上分配，但是必须指定大小
//char a1[] = "abc" 相当于在栈顶分配4个字节，分别放上a, b, c, \0
//char* pa = "abc" 分配在常量区，是不可修改的 最好写成const char* pa = "abc"; 可读不可写
//char a1[] = "abc" strlen(a1)会等于3 char a1[] = {'a', 'b', 'c'} strlen(a1) 会一直找到'\0'才认为是结尾
//char* pa = "abc" pa是个指向常量的指针
//cout char型指针时，本来应该输出地址，但是事实上输出字符串，这是cout函数的功能，如果想看地址的话，可以(int)强制转为地址
//char p[] = "abcde" sizeof(p)会输出数组大小
bool isUnique(char* string)
{
    bool alphabet[256];
    cout<<"Size:"<<sizeof(string)<<endl;
    cout<<"String: "<<string<<endl;
    char alpha = 'a';
    cout<<"String 1: "<<string[0]<<endl;
    return true;
}

//针对ASCII字符集合，只需要用256大小的数组来表征，时间复杂度为O(n)，空间复杂度为O(n)
bool isUnique_1(char* string)
{
    bool alphabet[256];
    memset(alphabet, 0, sizeof(alphabet));
    for(int i = 0; string[i] != '\0'; i++)
    {
        cout<<"char: "<<string[i]<<endl;
        int v = (int) string[i];
        if(alphabet[v]) return false;
        alphabet[v] = true;
    }
    return true;
}

//事实上我们可以进一步缩小所用的空间，我们用256bit来表示每一个字符对应的标志位，也就是说我们需要一个长度为8的int数组，每个int占32bit，通过这些细节的优化我们才能真正构建起可靠的程序
bool isUnique_2(char* string)
{
    int alphabet[8];
    int length = sizeof(int) * 8;
    memset(alphabet, 0, sizeof(alphabet));
    for(int i = 0; string[i] != '\0'; i++)
    {
        cout<<"char: "<<string[i]<<endl;
        int v = (int) string[i];
        int key_1 = alphabet[v / length];
        int key_2 = v % length;
        int key_3 = 1<<key_2;
        if(key_1 & key_3) return false;
        alphabet[v / length] = alphabet[v / length] | key_3;
    }
    return true;
}

//int a1[] = {1,3,9} cout<<a1<<endl; 会输出地址 cout<<*a1<<endl; 会输出首个字符
//char a[] = "abc"; char * pa = "def"; cout<<a<<endl; cout<<pa<<endl; 分别输出abc和def。这是cout的功能
//c++中，char *p = "zhangyuan"; 此时该字符串为常量，不可以用指针p修改 如果想修改，就要定义成char p[] = "zhangyuan";

int main()
{
    
    cout<<"Hello, World!\n"<<endl;    
    char s1[] = "1234567890qazxsw";
    /*s1[0] = 'a';
    cout<<"String: "<<s1<<endl;
    cout<<"Ans: "<<isUnique(s1)<<endl;
    cout<<"String: "<<s1<<endl;*/
    cout<<"isUnique: "<<isUnique_1(s1)<<endl;
    cout<<"isUnique: "<<isUnique_2(s1)<<endl;
    cout<<"size of int: "<<sizeof(int)<<endl;
    //左移相当于 *，使用<<
   /* int a = 1<<2;
    cout<<"Test: "<< a <<endl;*/
    return 0;
}