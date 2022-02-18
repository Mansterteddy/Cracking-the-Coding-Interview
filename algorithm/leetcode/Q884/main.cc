#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
    public:

        vector<string> split(string s){
            vector<string> res;
            int i = 0;
            while(i < s.size()){
                int j = i;
                while(j < s.size() && s[j] != ' '){
                    j++;
                }
                res.push_back(s.substr(i, j - i));
                i = j + 1;
            }
            return res;
        }

        vector<string> uncommonFromSentences(string s1, string s2){
            vector<string> res;
            if(s1 == "" && s2 == ""){
                return res;
            }

            vector<string> s1_vec = split(s1);
            vector<string> s2_vec = split(s2);

            unordered_map<string, int> s1_map;
            unordered_map<string, int> s2_map;

            for(auto s : s1_vec){
                s1_map[s]++;
            }

            for(auto s : s2_vec){
                s2_map[s]++;
            }

            for(auto s : s1_map){
                if(s2_map.find(s.first) == s2_map.end() && s.second == 1){
                    res.push_back(s.first);
                }
            }

            for(auto s : s2_map){
                if(s1_map.find(s.first) == s1_map.end() && s.second == 1){
                    res.push_back(s.first);
                }
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    auto res = s.uncommonFromSentences(s1, s2);
    for(auto i : res){
        cout << i << endl;
    }

    string s3 = "apple apple";
    string s4 = "banana";
    auto res2 = s.uncommonFromSentences(s3, s4);
    for(auto i : res2){
        cout << i << endl;
    }

    return 0;
}