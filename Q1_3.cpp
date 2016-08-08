//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

#include <iostream>
#include <string>

using namespace std;

//不能开一个数组，还是可以开一个固定大小，与问题规模无关的数组

//O(n*n) Time Complexity 如果只允许用额外的一到两个变量
void removeDuplicate(char* a)
{
    //length不包括最后的'\n'
    int length = strlen(a);
    for(int i = 0; i < length; i++)
    {
        char current_character = a[i];
        if (current_character == '\0')
        {
            break;
        }
        int cur = i + 1;
        for(int j = i + 1; j <= length; j++)
        {
            a[cur] = a[j];
            if(current_character != a[j]) cur++;  
        }
        cout<<"During: "<<a<<endl;
    }   
}

//如果可以开一个固定大小，与问题规模无关的数组，那么可以用一个数组来表征每个字符的出现，这样时间复杂度为O(n)
void removeDuplicate_1(char *a)
{
    //ASCII字符集 256个字符，int类型32位，用8个int即可
    int alphabet[8];
    int denominator = sizeof(int) * 8;
    memset(alphabet, 0, sizeof(alphabet));
    int length = strlen(a);
    int cur = 0;
    for(int i = 0; i <= length; i++)
    {
        a[cur] = a[i];
        char current_character = a[i];
        int index = int(current_character);
        int key_1 = alphabet[index / denominator];
        int key_2 = 1<<(index % denominator);
        int key_3 = key_2 & key_1;
        if (!key_3) 
        {
            alphabet[index / denominator] = (1<<(index % denominator)) | alphabet[index / denominator];
            cur++;
        }
        cout<<"During: "<<cur<<endl;
    }
}

//Test Case: abcd, aaaa, NULL, aaabbb, ababab 
int main()
{
    char a[] = "aaabbb ";
    removeDuplicate_1(a);
    cout<<"Removed String:"<<a<<endl;
    return 1;
}