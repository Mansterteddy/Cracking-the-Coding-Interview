#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int numDecodings(string s){
            
            if(s.size() == 0) return 0;
            if(s[0] == '0') return 0;
            if(s.size() == 1){
                return 1;
            }

            if(s.size() == 2){
                if(s[1] == '0'){
                    if(s[0] == '1' || s[0] == '2') return 1;
                    else return 0;
                }
                int cur_val = (s[0] - '0') * 10 + (s[1] - '0');
                if(cur_val > 26) return 1;
                else return 2;
            }

            int first_val = 1;
            int second_val = 0;

            int cur_val = (s[0] - '0') * 10 + (s[1] - '0');

            if(s[1] == '0'){
                if(s[0] != '1' && s[0] != '2') return 0;
                second_val = 1;
            }
            else if(cur_val > 26){
                second_val = 1;
            }
            else{
                second_val = 2;
            }

            for(int i = 2; i < s.size(); ++i){
                if(s[i] == '0'){
                    if(s[i-1] == '1' || s[i-1] == '2'){
                        cur_val = first_val;
                        first_val = second_val;
                        second_val = cur_val;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    int test_val = (s[i-1] - '0') * 10 + (s[i] - '0');
                    if(test_val > 26){
                        cur_val = second_val;
                        first_val = second_val;
                        second_val = cur_val;
                    }
                    else if(test_val < 10){
                        cur_val = second_val;
                        first_val = second_val;
                        second_val = cur_val;
                    }
                    else{
                        cur_val = first_val + second_val;
                        first_val = second_val;
                        second_val = cur_val;
                    }
                }
            }

            return cur_val;
        }
};

int main(){
    Solution s;

    //string str = "123123";
    string str = "1201234";
    str = "301";
    cout << s.numDecodings(str) << endl;

    return 0;
}
