//Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parenthese. 
//EXAMPLE:
//input: 3 (e.g., 3 pairs of parentheses)
//output: ((())), (()()), (())(), ()(()), ()()()
#include <iostream>

using namespace std;

//注意要加入一个match项，不能随便插入右括号，必须左括号的数量大于右括号的数量时，才能插入右括号
void parentheses(char *a, int n, int match, int pos)
{
    if(match == 0 && n == 0)
    {
        a[pos] = '\0';
        cout<<"Res: "<<a<<endl;
        return;
    }
    if(n == 0 && match != 0)
    {
        a[pos] = ')';
        parentheses(a, n, match - 1, pos + 1);
        return;
    }
    if(n != 0 && match == 0)
    {
        a[pos] = '(';
        parentheses(a, n - 1, match + 1, pos + 1);
    }
    else
    {
        a[pos] = ')';
        parentheses(a, n, match - 1, pos + 1);
        a[pos] = '(';
        parentheses(a, n - 1, match + 1, pos + 1);
    }
    return;
}


int main()
{
    char a[100];
    parentheses(a, 3, 0, 0);
    return 0;
}