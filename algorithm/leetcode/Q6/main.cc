#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string convert(string s, int numRows){
            
            if(numRows == 1) return s;

            string res = "";

            int str_len = s.length();
            int allNumRows = 2 * numRows - 2;

            for(int i = 0; i < numRows; ++i){

                if(i == 0 || i == numRows - 1){
                    int index = i;
                    while(index < str_len){
                        res += s[index];
                        index += allNumRows;
                    }
                }
                else{
                    int first_index = i;
                    int second_index = allNumRows - i;
                    while(first_index < str_len || second_index < str_len){
                        if(first_index < str_len){
                            res += s[first_index];
                            first_index += allNumRows;
                        }
                        if(second_index < str_len)
                        {
                            res += s[second_index];
                            second_index += allNumRows;
                        }
                    }
                }
            }

            return res;

        }
};

int main(){

    Solution s = Solution();
    
    string str = "PAYPALISHIRING";
    int numRows = 3;

    string res = s.convert(str, numRows);
    cout << res << endl;

    numRows = 4;
    res = s.convert(str, numRows);
    cout << res << endl;

    return 0;
}