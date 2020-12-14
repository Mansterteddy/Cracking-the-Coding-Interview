#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    string reformat(string str){
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<int>> hash_map;

        for(int i = 0; i < strs.size(); ++i){
            string hash_key = reformat(strs[i]);
            
            if(hash_map.find(hash_key) == hash_map.end()){
                vector<int> temp{i};
                hash_map[hash_key] = temp;
            }
            else{
                hash_map[hash_key].push_back(i);
            }
        }

        vector<vector<string>> res;
        for(auto hash_iter = hash_map.begin(); hash_iter != hash_map.end(); hash_iter++){
            //cout << hash_iter->first << endl;
            vector<string> temp_vec;
            for(int i = 0; i < hash_iter->second.size(); ++i){
                temp_vec.push_back(strs[hash_iter->second[i]]);
            }
            res.push_back(temp_vec);
        }

        return res;

    }
};

int main(){

    Solution s = Solution();

    vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = s.groupAnagrams(a);

    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}