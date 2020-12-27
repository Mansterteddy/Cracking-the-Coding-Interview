//Write code to reverse a C-Style String. (C-String means that "abcd" is represented as five characters, including the null characyer.)

#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//^是异或操作符，可以用来进行swap操作，不需要引入新的变量
void swap_1(char* a, char* b)
{
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
    cout<<"a: "<<*a<<" b:"<<*b<<endl;
}

void reverse_string(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    cout<<"Size of String: "<<i<<endl; 
    //int i = strlen(s);
    for(int j = 0; j <= i / 2 - 1; j++)
    {
        swap_1(&str[j], &str[i-1-j]);
    }
}

int main()
{
    char str[] = "Hello, World!";
    reverse_string(str);
    cout<<"Reversed Str is: "<<str<<endl;
    return 1;
}