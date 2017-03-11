//The count-and-say sequence is the sequence of integers begining as follows:
//1, 11, 21, 1211, 111221, ...
//1 is read as one one or 11
//11 is read as two one or 21
//21 is read as one two one one or 1211
//1211 is read as one one one two two one or 111221 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        string countAndSay(int n)
        {
            if(n == 1) return "1";
            n = n-1;
            vector<int> prev;
            vector<int> cur; 

            for(int i = 0; i < n; ++i)
            {   
                vector<int> count_vec;
                vector<int> val_vec;
                if(i == 0)
                {
                    count_vec.push_back(1);
                    val_vec.push_back(1);
                }
                else
                {
                    prev = cur;
                    cur.clear();
                    int prev_val;
                    int prev_count;
                    for(int i = 0; i < prev.size(); ++i)
                    {
                        if(i == 0)
                        {
                            prev_val = prev[i];
                            prev_count = 1;
                        }
                        else
                        {
                            if(prev_val == prev[i])
                            {
                                prev_count++;
                            }
                            else
                            {
                                val_vec.push_back(prev_val);
                                count_vec.push_back(prev_count);
                                prev_val = prev[i];
                                prev_count = 1;
                            }
                        }
                    }

                    val_vec.push_back(prev_val);
                    count_vec.push_back(prev_count);
                }

                for(int i = 0; i < count_vec.size(); ++i)
                {
                    cur.push_back(count_vec[i]);
                    cur.push_back(val_vec[i]);
                }
            }

            string res;
            for(int i = 0; i < cur.size(); ++i)
            {
                res += (char)(cur[i] + 48);
            }

            return res;
        }
};

int main()
{
    Solution s;

    int n = 1;
    string res = s.countAndSay(n);
    cout<<"res: "<<res<<endl;

    return 0;
}