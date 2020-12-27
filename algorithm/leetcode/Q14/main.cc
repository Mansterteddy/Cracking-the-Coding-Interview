#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        string longestCommonPrefixPair(string a, string b){
            string res = "";
            if(a.length() > b.length()){
                swap(a, b);
            }

            for(int i = 0; i < a.length(); ++i){
                if(a[i] == b[i])
                    res += a[i];
                else
                    break;
            }

            return res;
        }

        string longestCommonPrefix(vector<string>& strs){
            
            if(strs.size() == 0){
                return "";
            }
            else if(strs.size() == 1){
                return strs[0];
            }
            else if(strs.size() == 2){
                return longestCommonPrefixPair(strs[0], strs[1]);
            }
            else{
                string res = longestCommonPrefixPair(strs[0], strs[1]);
                for(int i = 2; i < strs.size(); i++){
                    res = longestCommonPrefixPair(res, strs[i]);
                    if(res == "")
                        return res;
                }

                return res;
            }

        }
};

int main(){

    Solution s = Solution();

    vector<string> a{"flower", "flow", "flight"};
    string res_a = s.longestCommonPrefix(a);
    cout << res_a << endl;

    vector<string> b{"dog", "racecar", "car"};
    string res_b = s.longestCommonPrefix(b);
    cout << res_b << endl;

    return 0;
}