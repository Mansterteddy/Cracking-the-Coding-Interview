#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
        {
            vector<vector<int>> res(matrix);

            int non_zero = 0;
            vector<pair<int, int>> vec;
            for(int i = 0; i < res.size(); ++i)
            {
                for(int j = 0; j < res[i].size(); ++j)
                {
                    if(res[i][j] == 1)
                    {
                        res[i][j] = -1;
                        non_zero++;
                    }
                    else
                    {
                        pair<int, int> p;
                        p.first = i;
                        p.second = j;
                        vec.push_back(p);
                    }
                }
            } 

            int now = 0;

            while(non_zero > 0)
            {
                now++;
                vector<pair<int, int>> new_vec;
                for(int i = 0; i < vec.size(); ++i)
                {
                    int x = vec[i].first;
                    int y = vec[i].second;

                    if(x - 1 >= 0 && res[x-1][y] == -1)
                    {
                        res[x-1][y] = now;
                        non_zero--;
                        pair<int, int> new_pair;
                        new_pair.first = x-1;
                        new_pair.second = y;
                        new_vec.push_back(new_pair);
                    }

                    if(x + 1 < res.size() && res[x+1][y] == -1)
                    {
                        res[x+1][y] = now;
                        non_zero--;
                        pair<int, int> new_pair;
                        new_pair.first = x+1;
                        new_pair.second = y;
                        new_vec.push_back(new_pair);
                    }

                    if(y - 1 >= 0 && res[x][y-1] == -1)
                    {
                        res[x][y-1] = now;
                        non_zero--;
                        pair<int, int> new_pair;
                        new_pair.first = x;
                        new_pair.second = y-1;
                        new_vec.push_back(new_pair);
                    }

                    if(y + 1 < res[0].size() && res[x][y+1] == -1)
                    {
                        res[x][y+1] = now;
                        non_zero--;
                        pair<int, int> new_pair;
                        new_pair.first = x;
                        new_pair.second = y+1;
                        new_vec.push_back(new_pair);
                    }
                }
                vec = new_vec;
            }


            return res;
        }
};

int main()
{
    vector<int> v_1 = {0, 0, 0};
    vector<int> v_2 = {0, 1, 0};
    vector<int> v_3 = {1, 1, 1};
    vector<vector<int>> v = {v_1, v_2, v_3};

    Solution s;
    vector<vector<int>> res = s.updateMatrix(v);

    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    } 

    return 0;
}