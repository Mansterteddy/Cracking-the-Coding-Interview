#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

        vector<string> generate(int left_n, int right_n){
            
            //cout << "Enter: " << left_n << " " << right_n << endl;

            if(left_n == 0){
                string cur_res = "";
                for(int i = 0; i < right_n; ++i){
                    cur_res += ")";
                }
                vector<string> res{cur_res};
                return res;
            }

            vector<string> res;

            if(left_n <= right_n){

                vector<string> res_1 = generate(left_n - 1, right_n);
                for(auto item : res_1){
                    string temp_res = "(" + item;
                    res.push_back(temp_res);
                    //cout << "res_1: " << temp_res << endl;
                }

                //cout << "end res_1." << endl;

                vector<string> res_2 = generate(left_n, right_n - 1);
                for(auto item : res_2){
                    string temp_res = ")" + item;
                    res.push_back(temp_res);
                    //cout << "res_2: " << temp_res << endl;
                }

            }

            return res;

        }


        vector<string> generateParenthesis(int n){
            
            if(n == 1){
                vector<string> res{"()"};
                return res;
            }

            vector<string> cur_res = generate(n-1, n);
            vector<string> res;
            for(auto item : cur_res){
                res.push_back("(" + item);
            }
            
            return res;
        }
};

int main(){

    Solution s = Solution();

    int n = 1;

    vector<string> res = s.generateParenthesis(n);

    for(auto item : res){
        cout << item << " ";
    }
    cout << endl;

    n = 3;
    res = s.generateParenthesis(n);

    for(auto item : res){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}