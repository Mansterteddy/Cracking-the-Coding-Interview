#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle){
            
            if(haystack == needle) return 0;

            int first_len = haystack.length();
            int second_len = needle.length();

            if(second_len == 0) return 0;

            int final_index = first_len - second_len;

            int res = -1;

            int index = 0;
            int next_index = 0;
            bool flag = false;

            while(index <= final_index){
                if(haystack[index] == needle[0]){
                    for(int i = 1; i < second_len; ++i){
                        if(haystack[index + i] == needle[0] && flag == false){
                            next_index = index + i;
                            flag = true;
                        }
                        if((i == second_len - 1) && haystack[index + i] == needle[i]){
                            return index;
                        }
                        if(haystack[index + i] != needle[i]){
                            break;
                        }
                    }
                    if(flag){
                        index = next_index;
                        flag = false;
                    }
                    else{
                        index += 1;
                    }

                }
                else{
                    index += 1;
                }
            } 

            return res;  
        }
};

int main(){

    Solution s = Solution();

    string first = "hello";
    string second = "ll";
    int res = s.strStr(first, second);
    cout << res << endl;

    first = "aaaaa";
    second = "bba";
    res = s.strStr(first, second);
    cout << res << endl;

    first = "abc";
    second = "c";
    res = s.strStr()

    return 0;
}