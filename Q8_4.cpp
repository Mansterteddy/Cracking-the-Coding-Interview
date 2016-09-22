//Write a method to compute all permutations of a string.
#include <iostream>

using namespace std;

void print_permutations(char *a, int start, int length)
{
    if(length == 1)
    {
        cout<<"A: "<<a<<endl;
        return;
    }
    //for()
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

int main()
{
    char a[] = "helo";
    int length = sizeof(a) / sizeof(a[0]);
    print_permutations(a, 0, length);
    return 0;
}