#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:

        vector<vector<string>> recursiveRestore(string s, int start, int index, int total_len){

            vector<vector<string>> res;

            if(index == 3){
                
                if(start >= total_len) return res;
                
                if(total_len - start > 3){
                    return res;
                }

                if(s[start] == '0'){
                    if(total_len - start == 1){
                        vector<string> tmp;
                        tmp.push_back(s.substr(start, 1));
                        res.push_back(tmp);
                        return res;
                    }
                    else{
                        return res;
                    }
                }

                //cout << s.substr(start, total_len - start) << " " << total_len - start << endl;

                if(total_len - start == 3){
                    int num = (s[start] - '0') * 100 + (s[start+1] - '0') * 10 + (s[start+2] - '0');
                    if(num > 255)
                        return res;
                    else{
                        vector<string> tmp;
                        tmp.push_back(s.substr(start, 3));
                        res.push_back(tmp);
                        return res;
                    }
                }
                else{
                    vector<string> tmp;
                    tmp.push_back(s.substr(start, total_len - start));
                    res.push_back(tmp);
                    return res;
                }
            }
            else{

                if(total_len - start > 3 * (4 - index)){
                    return res;
                }

                if(s[start] == '0'){
                    auto res_tmp = recursiveRestore(s, start + 1, index + 1, total_len);
                    if(res_tmp.size() != 0){
                        for(auto item: res_tmp){
                            vector<string> new_item{s.substr(start, 1)};
                            for(auto sub_item: item){
                                new_item.push_back(sub_item);
                            }
                            res.push_back(new_item);
                        }
                    }
                    return res;
                }

                string s1 = s.substr(start, 1);
                if(total_len - start < 1) return res;
                auto res_1 = recursiveRestore(s, start + 1, index + 1, total_len);
                //cout << "index: " << index << " res_1: " << res_1.size() << endl;
                if(res_1.size() != 0){
                    for(auto item: res_1){
                        vector<string> new_item{s.substr(start, 1)};
                        for(auto sub_item: item){
                            new_item.push_back(sub_item);
                        }
                        res.push_back(new_item);
                    }
                }

                string s2 = s.substr(start, 2);
                if(total_len - start < 2) return res;
                auto res_2 = recursiveRestore(s, start + 2, index + 1, total_len);
                //cout << "index: " << index << " res_2: " << res_2.size() << endl;
                if(res_2.size() != 0){
                    for(auto item: res_2){
                        vector<string> new_item{s.substr(start, 2)};
                        for(auto sub_item: item){
                            new_item.push_back(sub_item);
                        }
                        res.push_back(new_item);
                    }
                }

                string s3 = s.substr(start, 3);
                if(total_len - start < 3) return res;
                int num = (s[start] - '0') * 100 + (s[start+1] - '0') * 10 + (s[start+2] - '0');
                if(num <= 255){
                    auto res_3 = recursiveRestore(s, start + 3, index + 1, total_len);
                    //cout << "index: " << index << " res_3: " << res_3.size() << endl;
                    if(res_3.size() != 0){
                        for(auto item: res_3){
                            vector<string> new_item{s.substr(start, 3)};
                            for(auto sub_item: item){
                                new_item.push_back(sub_item);
                            }
                            res.push_back(new_item);
                        }
                    }
                }

            }
            
            return res;
        }

        vector<string> restoreIpAddresses(string s){

            vector<string> res;

            if(s.length() < 4) return res;

            if(s.length() == 4){
                string cur_res = "";
                for(int i = 0; i < 4; ++i){
                    cur_res += s[i];
                    if(i != 3) cur_res += '.';
                }
                res.push_back(cur_res);
                return res;
            }

            auto string_res = recursiveRestore(s, 0, 0, s.length());
            
            for(auto item: string_res){
                string cur_str = "";            
                for(int i = 0; i < 4; ++i){
                    cur_str += item[i];
                    if(i != 3) cur_str += '.';
                }
                res.push_back(cur_str);
            }

            return res;
        }
};

int main(){

    Solution s = Solution();

    auto res_1 = s.restoreIpAddresses("25525511135");
    for(auto item: res_1){
        cout << item << " ";
    }
    cout << endl;

    auto res_2 = s.restoreIpAddresses("0000");
    for(auto item: res_2){
        cout << item << " ";
    }
    cout << endl;

    auto res_3 = s.restoreIpAddresses("101023");
    for(auto item: res_3){
        cout << item << " ";
    }
    cout << endl;

    return 0;

}