//Given a digit string, return all possible letter combinations that the number could represent

//Recursion
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:

        vector<string> recursive_way(string digits, int index)
        {
            vector<string> res;

            int index_test = (int)digits[index] - 48;

            if(index == digits.size() - 1)
            {
                vector<char> vector_char = remark[index_test - 2];
                for(int i = 0; i < vector_char.size(); ++i)
                {
                    string str_ans;
                    str_ans.push_back(vector_char[i]);
                    res.push_back(str_ans);
                }
                return res;
            }
            else
            {
                vector<string> vec_string = recursive_way(digits, index + 1);
                vector<char> vector_char = remark[index_test - 2];
                for(int i = 0; i < vector_char.size(); ++i)
                {
                    string str_ans;
                    str_ans.push_back(vector_char[i]);
                    for(int j = 0; j < vec_string.size(); ++j)
                    {
                        string str_res = vec_string[j];
                        str_res = str_ans + str_res;
                        res.push_back(str_res); 
                    }
                }
            }

            return res;
        }

        vector<string> letterCombinations(string digits)
        {
            vector<char> a_2 = {'a', 'b', 'c'};
            remark.push_back(a_2);
            vector<char> a_3 = {'d', 'e', 'f'};
            remark.push_back(a_3);
            vector<char> a_4 = {'g', 'h', 'i'};
            remark.push_back(a_4);
            vector<char> a_5 = {'j', 'k', 'l'};
            remark.push_back(a_5);
            vector<char> a_6 = {'m', 'n', 'o'};
            remark.push_back(a_6);
            vector<char> a_7 = {'p', 'q', 'r', 's'};
            remark.push_back(a_7);
            vector<char> a_8 = {'t', 'u', 'v'};
            remark.push_back(a_8);
            vector<char> a_9 = {'w', 'x', 'y', 'z'};
            remark.push_back(a_9);

            vector<string> res;
            if(digits.size() == 0) return res;
            res = recursive_way(digits, 0);            
            return res;
        }

        private:  
            vector<vector<char>> remark;      
};

int main()
{
    Solution s;

    string digits = "23";
    vector<string> res = s.letterCombinations(digits);
    for(int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<endl;
    }

    return 0;
}