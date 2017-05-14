//Write a method to compute all permutations of a string.
#include <iostream>

using namespace std;

//采用交换的思路，交换当前字符和后面字符串中的字符
void print_permutations(char *a, int start, int length)
{
    if(length == 1)
    {
        cout<<"A: "<<a<<endl;
        return;
    }
    for(int i = start; a[i] != '\0'; i++)
    {
        char temp = a[i];
        a[i] = a[start];
        a[start] = temp;
       // cout<<"In: "<<a<<endl;
        print_permutations(a, start + 1, length - 1);
        a[start] = a[i];
        a[i] = temp;
    }
}

//n个字符会产生n!中排列
//采用插入的思路，计算abc时，计算bc的排列，bc、cb，然后对bc的前中后三个位置将a插入进去

int main()
{
    char a[] = "helo";
    int length = sizeof(a) / sizeof(a[0]);
    print_permutations(a, 0, length);
    return 0;
}