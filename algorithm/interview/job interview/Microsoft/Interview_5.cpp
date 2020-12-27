//把Interview_4中的问题，从一维升级为二维，上一个问题是直接找中点，这个问题应该是找行和列的中线。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

    int findLocalMax(vector<vector<int>> v)
    {
        return iterative_findMax(v, 0, v[0].size() - 1, 0, v.size() - 1);
    }

    vector<int> line_x_findMax(vector<vector<int>>& v, int start_x, int end_x, int y)
    {
        int x = start_x;
        int max = v[y][x];
        for(int i = start_x; i <= end_x; ++i)
        {
            if(max < v[y][i])
            {
                x = i;
                max = v[y][i];
            }
            cout<<"y: "<<y<<" x: "<<x<<" max: "<<max<<endl;  
        }

        vector<int> res = {y, x, max};
        return res;
    }

    vector<int> line_y_findMax(vector<vector<int>>& v, int start_y, int end_y, int x)
    {
        int y = start_y;
        int max = v[y][x];
        for(int i = start_y; i <= end_y; ++i)
        {
            if(max < v[i][x])
            {
                y = i;
                max = v[i][x];
            }
            cout<<"y: "<<y<<" x: "<<x<<" max: "<<max<<endl;  

        }

        vector<int> res = {y, x, max};
        return res;
    }

    int iterative_findMax(vector<vector<int>>& v, int start_x, int end_x, int start_y, int end_y)
    {
        /*
        不好处理的情况，就作为基础情况处理干净。
        */
        if(start_x == end_x)
        {
            vector<int> res = line_y_findMax(v, start_y, end_y, start_x);
            return res[2];
        }

        if(start_y == end_y)
        {
            vector<int> res = line_x_findMax(v, start_x, end_x, start_y);
            return res[2];
        }

        if(end_x - start_x == 1)
        {
            vector<int> res_1 = line_y_findMax(v, start_y, end_y, start_x);
            vector<int> res_2 = line_y_findMax(v, start_y, end_y, end_x);
            return res_1[2] > res_2[2] ? res_1[2] : res_2[2];
        }

        if(end_y - start_y == 1)
        {
            vector<int> res_1 = line_x_findMax(v, start_x, end_x, start_y);
            vector<int> res_2 = line_x_findMax(v, start_x, end_x, end_y);
            return res_1[2] > res_2[2] ? res_1[2] : res_2[2];
        }

        int mid_x = (start_x + end_x) / 2;
        int mid_y = (start_y + end_y) / 2;

        vector<int> line_x = line_x_findMax(v, start_x, end_x, mid_y);
        vector<int> line_y = line_y_findMax(v, start_y, end_y, mid_x);

        cout<<"line_x: "<<line_x[2]<<" line_y: "<<line_y[2]<<endl;

        if(line_x[2] == line_y[2])
        {
            return line_x[2];
        }
        else if(line_x[2] > line_y[2])
        {
            int lim_x = line_x[1];
            int lim_y = line_x[0];
            if(v[lim_y][lim_x] < v[lim_y-1][lim_x])
            {
                if(lim_x < mid_x)
                {
                    return iterative_findMax(v, start_x, mid_x - 1, start_y, mid_y - 1);
                }
                if(lim_x > mid_x)
                {
                    return iterative_findMax(v, mid_x + 1, end_x, start_y, mid_y - 1);
                }
            }

            if(v[lim_y][lim_x] < v[lim_y+1][lim_x])
            {
                if(lim_x < mid_x)
                {
                    return iterative_findMax(v, start_x, mid_x - 1, mid_y + 1, end_y);
                }
                if(lim_x > mid_x)
                {
                    return iterative_findMax(v, mid_x + 1, end_x, mid_y + 1, end_y);
                }
            }

            return v[lim_y][lim_x];
        }
        else
        {            
            int lim_x = line_y[1];
            int lim_y = line_y[0];
            if(v[lim_y][lim_x] < v[lim_y][lim_x - 1])
            {
                if(lim_y < mid_y)
                {
                    return iterative_findMax(v, start_x, mid_x - 1, start_y, mid_y - 1);
                }
                if(lim_y > mid_y)
                {
                    return iterative_findMax(v, start_x, mid_x - 1, mid_y + 1, end_y);
                }
            }

            if(v[lim_y][lim_x] < v[lim_y][lim_x + 1])
            {
                if(lim_y < mid_y)
                {
                    return iterative_findMax(v, mid_x + 1, end_x, start_y, mid_y - 1);
                }
                if(lim_y > mid_y)
                {
                    return iterative_findMax(v, mid_x + 1, end_x, mid_y + 1, end_y);
                }
            }

            return v[lim_y][lim_x];
        }


    }

};

int main()
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {-5, -3, -2};
    vector<int> v3 = {-4, -1, 0};

    vector<vector<int>> v = {v1, v2, v3};

    Solution s;
    int res = s.findLocalMax(v);
    cout<<"res: "<<res<<endl;

    return 0;
}