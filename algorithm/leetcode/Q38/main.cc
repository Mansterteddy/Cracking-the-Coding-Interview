#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string countAndSay(int n){

            string pre_str = "";
            string cur_str = "1";

            for(int i = 1; i < n; ++i){

                pre_str = cur_str;
                cur_str = "";

                //cout << "pre_str: " << pre_str << endl;
                //cout << "cur_str: " << cur_str << endl;

                int start = 0;
                int end = 0;
                
                while(end < pre_str.size()){
                    
                    while(end < pre_str.size() && pre_str[start] == pre_str[end]){
                        end += 1;
                    }

                    cur_str += ('0' + (end - start));
                    cur_str += pre_str[start];
                    //cout << "debug: " << cur_str << endl;
                    start = end;
                }

            }

            return cur_str;
        }
};

int main(){

    Solution s = Solution();

    int n = 1;
    string res = s.countAndSay(n);
    cout << res << endl;

    n = 5;
    res = s.countAndSay(n);
    cout << res << endl;

    return 0;
}