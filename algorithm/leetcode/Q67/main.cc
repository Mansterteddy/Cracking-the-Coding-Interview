#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string addBinary(string a, string b){
            string res = "";
            int next_val = 0;
            int index = 0;

            while(index < a.size() || index < b.size()){

                int a_cur_index = a.size() - index - 1;
                int b_cur_index = b.size() - index - 1;

                if(index >= a.size()){
                    if(b[b_cur_index] == '0' && next_val == 0)
                    {
                        res = "0" + res;
                        next_val = 0;
                    }
                    else if(b[b_cur_index] == '0' && next_val == 1)
                    {
                        res = "1" + res;
                        next_val = 0;
                    }
                    else if(b[b_cur_index] == '1' && next_val == 0)
                    {
                        res = "1" + res;
                        next_val = 0;
                    }
                    else
                    {
                        res = "0" + res;
                        next_val = 1;
                    }
                }
                else if(index >= b.size()){
                    if(a[a_cur_index] == '0' && next_val == 0)
                    {
                        res = "0" + res;
                        next_val = 0;
                    }
                    else if(a[a_cur_index] == '0' && next_val == 1)
                    {
                        res = "1" + res;
                        next_val = 0;
                    }
                    else if(a[a_cur_index] == '1' && next_val == 0)
                    {
                        res = "1" + res;
                        next_val = 0;
                    }
                    else
                    {
                        res = "0" + res;
                        next_val = 1;
                    }
                }
                else{
                    //cout << "Debug: " << a[index] << " " << b[index] << endl;

                    if(a[a_cur_index] == '1' && b[b_cur_index] == '1'){
                        if(next_val == 1){
                            res = "1" + res;
                            next_val = 1;
                        }
                        else{
                            res = "0" + res;
                            next_val = 1;
                        }
                    }
                    else if(a[a_cur_index] == '0' && b[b_cur_index] == '1'){
                        if(next_val == 1){
                            res = "0" + res;
                            next_val = 1;
                        }
                        else{
                            res = "1" + res;
                            next_val = 0;
                        }
                    }
                    else if(a[a_cur_index] == '1' && b[b_cur_index] == '0'){
                        if(next_val == 1){
                            res = "0" + res;
                            next_val = 1;
                        }
                        else{
                            res = "1" + res;
                            next_val = 0;
                        }
                    }
                    else{
                        if(next_val == 1){
                            res = "1" + res;
                            next_val = 0;
                        }
                        else{
                            res = "0" + res;
                            next_val = 0;
                        }
                    }
                }
                index += 1;
            }
            
            if(next_val == 1)
                res = "1" + res;

            return res;
        }
};

int main(){

    Solution s = Solution();

    string a = "11";
    string b = "1";
    auto res = s.addBinary(a, b);
    cout << res << endl;

    a = "1010";
    b = "1011";
    res = s.addBinary(a, b);
    cout << res << endl;

    return 0;
}