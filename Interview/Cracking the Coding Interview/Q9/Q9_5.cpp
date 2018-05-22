//Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string. 
//Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”,“”, “dad”, “”, “”] will return 4
//Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
#include <iostream>

using namespace std;
//仍然是二分搜索，但是由于数组中有空字符串，因此还要加些额外处理，否则无法在二分搜索时对比大小
//如果遇到空字符时，就向右移动，直到字符串不为空，或者位置越界
int search(string s[], int low, int high, string x)
{
    if(x == "") return -1;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        int t = mid;
        while(s[t] == "" && t <= high) ++t;
        if(t > high) high = mid - 1;
        else
        {
            if(s[t] == x) return t;
            else if(s[t] < x) low = t + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}