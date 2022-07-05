#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
    public:
        vector<int> findSubstring(string s, vector<string>& words){

            vector<int> res;
            if(s == "") return res;
            if(words.size() == 0) return res;

            int word_len = words[0].size();
            int word_list_size = words.size();

            vector<string> final_str_vec;
            for(auto item: words){
                final_str_vec.push_back(item);
            }
            sort(final_str_vec.begin(), final_str_vec.end());

            set<string> word_set;
            for(auto item: words){
                if(word_set.find(item) == word_set.end()){
                    word_set.insert(item);
                }
            }

            set<int> potential_candidates;
            for(int i = 0; i < s.length(); i++){
                string temp_str = s.substr(i, word_len);
                if(word_set.find(temp_str) != word_set.end()){
                    potential_candidates.insert(i);
                }
            }
            //cout << "potential candidates size: " << potential_candidates.size() << endl;

            vector<int> filtered_candidates;
            for(auto item: potential_candidates){
                bool flag = true;
                for(int i = 1; i < word_list_size; ++i){
                    int next_index = item + word_len * i;
                    if(potential_candidates.find(next_index) == potential_candidates.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    filtered_candidates.push_back(item);
                }
            }

            /*
            cout << "filtered candidates: " << endl;
            for(auto item: filtered_candidates){
                cout << item << " ";
            }
            cout << endl;*/

            for(auto item: filtered_candidates){
                vector<string> temp;
                int start_index = item;

                for(int i = 0; i < word_list_size; ++i){
                    int next_index = start_index + word_len * i;
                    string temp_str = s.substr(next_index, word_len);
                    temp.push_back(temp_str);
                }

                sort(temp.begin(), temp.end());
                if(temp == final_str_vec){
                    res.push_back(item);
                }
            }
            
            return res;
        }
};

int main(){

    Solution s = Solution();

    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> res1 = s.findSubstring(s1, words1);
    for(auto i: res1)
        cout << i << " ";
    cout << endl;

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> res2 = s.findSubstring(s2, words2);
    for(auto i: res2)
        cout << i << " ";
    cout << endl;
    
    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> res3 = s.findSubstring(s3, words3);
    for(auto i: res3)
        cout << i << " ";
    cout << endl;

    return 0;
}