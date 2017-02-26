/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
*/

//Tag: Greedy

#include <map>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string>& words)
        {
            vector<int> res;
            int len_word = words[0].size();
            map<string, vector<int>> sup_map;
            map<int, string> sup_map_int;

            for(int i = 0; i < words.size(); ++i)
            {
                int index = 0;
                if(sup_map[words[i]].size() != 0) continue;
                while(s.find(words[i], index) != string::npos)
                {
                    int key = s.find(words[i], index);
                    sup_map[words[i]].push_back(key);
                    sup_map_int[key] = words[i];
                    index = key + 1;
                }
            }

            for(int i = 0; i < words.size(); ++i)
            {
                cout<<"Word: "<<words[i]<<" size: "<<sup_map[words[i]].size()<<endl;
                for(int j = 0; j < sup_map[words[i]].size(); ++j)
                {
                    cout<<sup_map[words[i]][j]<<" ";
                }
                cout<<endl;
            }

            priority_queue<int, vector<int>, greater<int>> pq1;
                
            for(int i = 0; i < words.size(); ++i)
            {
                if(sup_map[words[i]].size() == 0)
                {
                    break;
                }
                else
                {
                    pq1.push(sup_map[words[i]][0]);
                    sup_map[words[i]].erase(sup_map[words[i]].begin());
                }
            }

            while(true)
            {
                if(pq1.size() != words.size()) break;

                bool val = make_sure(pq1, len_word);
                
                if(val == true)
                {
                    res.push_back(pq1.top());
                }

                string word_name = sup_map_int[pq1.top()];
                pq1.pop();
                if(sup_map[word_name].size() == 0) break;
                pq1.push(sup_map[word_name][0]);
                sup_map[word_name].erase(sup_map[word_name].begin());
            }

            return res;

        }

    private:
            bool make_sure(priority_queue<int, vector<int>, greater<int>> pq, int len_word)
            {
                int length = pq.size();
                int prev;

                for(int i = 0; i < length; ++i)
                {
                    if(i == 0)
                    {
                        prev = pq.top();
                        pq.pop();
                    }
                    else
                    {
                        int cur = pq.top();
                        if(cur - prev != len_word) return false;
                        pq.pop();
                        prev = cur;
                    }
                }

                return true;
            }
};


class Solution1
{
    public:
        vector<int> findSubstring(string s, vector<string>& words) 
        {
            vector<int> res;
            vector<vector<int>> sup(words.size());
            int len_word = words[0].size();
            map<int, int> sup_map;

            for(int i = 0; i < words.size(); ++i)
            {
                int index = 0;
                while(s.find(words[i], index) != string::npos)
                {
                    cout<<"index: "<<index<<" ans: "<<s.find(words[i], index)<<endl;
                    int key = s.find(words[i], index);
                    sup[i].push_back(key);
                    sup_map[key] = i;
                    index = index + key + 1;
                }
            }

            cout<<"show: "<<endl;  
            for(int i = 0; i < sup.size(); ++i)
            {
                for(int j = 0; j < sup[i].size(); ++j)
                {
                    cout<<sup[i][j]<<" ";
                }
                cout<<endl;
            }
            
            priority_queue<int, vector<int>, greater<int>> pq1;

            for(int i = 0; i < sup.size(); ++i)
            {
                if(sup[i].size() == 0)
                {
                    break;
                }
                else
                {
                    pq1.push(sup[i][0]);
                    sup_map[sup[i][0]] = i;
                    sup[i].erase(sup[i].begin());
                }
            }

            while(true)
            {
                if(pq1.size() != words.size()) break;

                bool val = make_sure(pq1, len_word);

                if(val == true)
                {
                    res.push_back(pq1.top());
                }
                int vec_index = sup_map[pq1.top()];
                pq1.pop();
                if(sup[vec_index].size() == 0) break;
                pq1.push(sup[vec_index][0]);
                sup[vec_index].erase(sup[vec_index].begin());
            }

            return res;
        }

        private:
            bool make_sure(priority_queue<int, vector<int>, greater<int>> pq, int len_word)
            {
                int length = pq.size();
                int prev;

                for(int i = 0; i < length; ++i)
                {
                    if(i == 0)
                    {
                        prev = pq.top();
                        pq.pop();
                    }
                    else
                    {
                        int cur = pq.top();
                        if(cur - prev != len_word) return false;
                        pq.pop();
                        prev = cur;
                    }
                }

                return true;
            }
};

int main()
{
    Solution s;

    string str = "barfoobarthefoobarbarfooman";
    vector<string> vec = {"bar", "foo", "bar"};

    str = "aaaaaa";
    vec = {"aaa", "aaa"};

    vector<int> res = s.findSubstring(str, vec);
    
    for(int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}