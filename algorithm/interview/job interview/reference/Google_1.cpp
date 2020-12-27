#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		vector<vector<int>> solveDistance(vector<vector<int>> vec)
    {
	    vector<vector<int>> res;
		int len = vec.size();
		for(int i = 0; i < len; ++i)
        {
		    vector<int> res_son(len, -1);
	        res.push_back(res_son);
        }

        for(int i = 0; i < len; ++i)
        {
	        for(int j = 0; j < len; ++j)
            {
		        if(vec[i][j] == 0) res[i][j] = 0;
            }
        }


        for(int i = 0; i < len; ++i)
        {
	        for(int j = 0; j < len; ++j)
            {
	            if(res[i][j] != -1) continue;
	            find(vec, res, i, j);
            }
        }


        return res;

	}

    void find(vector<vector<int>> vec, vector<vector<int>>& res, int p, int q)
    {
        cout<<"find: "<<p<<" "<<q<<endl;
	    int len = vec.size();

	    if(p < 0 || q < 0 || p >= len || q >= len) return;
        if(res[p][q] != -1) return;

        cout<<"continue!"<<endl;
        find(vec, res, p-1, q);
        find(vec, res, p+1, q);
        find(vec, res, p, q-1);
        find(vec, res, p, q+1);


        vector<int> sq;
        if(p-1 >= 0 && res[p-1][q] != -1) sq.push_back(res[p-1][q]);
        else if(p+1 < len && res[p+1][q] != -1) sq.push_back(res[p+1][q]); 
        else if(q-1 >= 0 && res[p][q-1] != -1)  sq.push_back(res[p][q-1]);
        else if(q+1 < len && res[p][q+1] != -1) sq.push_back(res[p][q+1]);

        int min = sq[0];
        for(int i = 1; i < sq.size(); ++i)
        {
            if(min > sq[i]) min = sq[i];
        }
        /*
        if(p == 0)
        {
            if(q == 0) res[p][q] = min(res[p+1][q], res[p][q+1]);
            else if(q == len - 1) res[p][q] = min(res[p][q-1], res[p+1][q]);
            else 
            {
                res[p][q] = min(res[p+1][q], min(res[p][q-1], res[p][q+1]));
            }
        }
        else if(p == len-1)
        {
            cout<<"Enter: "<<p<<" "<<q<<endl;
            if(q == 0) res[p][q] = min(res[p][q-1], res[p-1][q]);
            else if(q == len-1) res[p][q] = min(res[p][q-1], res[p-1][q]);
            else 
            {
                res[p][q] = min(res[p][q-1], min(res[p-1][q], res[p][q+1]));
            }
        }
        else if(q == 0)
        {
	        res[p][q] = min(res[p+1][q], min(res[p-1][q], res[p][q+1]));
        }
        else if(q == len -1)
        {
	        res[p][q] = min(res[p+1][q], min(res[p-1][q], res[p][q-1]));
        }
        else
        {
            res[p][q] = min(min(res[p+1][q], res[p-1][q]), min(res[p][q-1], res[p][q+1]));	
        }*/

        res[p][q] = min + 1;

    }

};

int main()
{
    vector<vector<int>> vec;
    vector<int> v_1 = {0, 1, 0};
    vector<int> v_2 = {1, 1, 1};
    vector<int> v_3 = {0, 1, 0};
    vec = {v_1, v_2, v_3};

    Solution s;
    vector<vector<int>> res = s.solveDistance(vec);

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
