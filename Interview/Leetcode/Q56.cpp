#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i_1, Interval i_2)
{
    if(i_1.start != i_2.start)
    {
        return i_1.start < i_2.start;
    }
    else
    {
        return i_1.end <= i_2.end;
    }
}

class Solution
{
    vector<Interval> merge(vector<Interval>& ins) 
    {
        if (ins.empty()) return vector<Interval>{};
        vector<Interval> res;
        sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
        res.push_back(ins[0]);
        for (int i = 1; i < ins.size(); i++) 
        {
            if (res.back().end < ins[i].start) res.push_back(ins[i]);
            else
                res.back().end = max(res.back().end, ins[i].end);
        }
        return res;
    }
}


class Solution1
{
    public:

    int findPos(vector<Interval> sup, int val)
    {
        int start = 0;
        int end = sup.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(val == sup[mid].start) return mid;
            else if(val > sup[mid].start)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start;
    }

    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> res_vec;
        if(intervals.size() == 0) return res_vec;

        sort(intervals.begin(), intervals.end(), cmp);
            
        vector<int> merge_vec;

        for(int i = 0; i < intervals.size(); ++i)
        {
            int pos = findPos(intervals, intervals[i].end);
            //cout<<"pos: "<<pos<<endl;
            merge_vec.push_back(pos);
        }

        for(int i = 0; i < merge_vec.size(); ++i)
        {
            int start = intervals[i].start;
            int end_index = merge_vec[i];
            int end_cmp_1 = intervals[end_index-1].end;
            int end_cmp_2 = intervals[i].end;
            int end = (end_cmp_1 > end_cmp_2) ? end_cmp_1 : end_cmp_2;
            res_vec.push_back(Interval(start, end));
        }

        vector<vector<Interval>::iterator> erase_index;
        vector<Interval>::iterator iter;
        for(iter = res_vec.begin(); iter != res_vec.end(); ++iter)
        {
            if(iter < res_vec.end() - 1)
            {
                //cout<<"iter: "<<iter->end<<" next iter: "<<(iter + 1)->start<<endl;
                if(iter->end > (iter + 1)->start)
                {
                    (iter + 1)->start = iter->start;
                    (iter + 1)->end = (iter->end > (iter + 1)->end) ? iter->end : (iter+1)->end;
                    erase_index.push_back(iter);
                    //res_vec.erase(iter);
                }
                else continue;
            }
        }

        for(int i = erase_index.size() - 1; i >= 0; --i)
        {
            res_vec.erase(erase_index[i]);
        }

        return res_vec;
    }
};

int main()
{
    Interval i_1(1, 7), i_2(2, 6), i_3(8, 19), i_4(15, 18), i_5(1, 4);
    vector<Interval> v = {i_1, i_2, i_3, i_4, i_5};

    Solution s;

    vector<Interval> res = s.merge(v);

    for(int i = 0; i < res.size(); ++i)
    {
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }

    return 0;
}