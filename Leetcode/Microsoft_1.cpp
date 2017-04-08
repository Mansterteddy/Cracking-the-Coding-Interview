#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N;
    cin>>N;

    vector<pair<int, int>> pos_vec;

    for(int i = 0; i < N; ++i)
    {
        pair<int, int> pos;
        int a, b;
        cin>>a>>b;
        pos.first = a;
        pos.second = b;
        pos_vec.push_back(pos);
    }

    int res = 0;

    map<int, int> m1;
    for(int i = 0; i < pos_vec.size(); ++i)
    {
        int val = pos_vec[i].first;
        if(m1.find(val) == m1.end())
        {
            m1[val] = 1;
        }
        else
        {
            m1[val]++;
        }
    }

    map<int, int>::iterator m1_iter;
    for(m1_iter = m1.begin(); m1_iter != m1.end(); ++m1_iter)
    {
        //cout<<m1_iter->first<<" "<<m1_iter->second<<endl;
        res += m1_iter->second * (m1_iter->second - 1) / 2;
    }


    map<int, int> m2;
    for(int i = 0; i < pos_vec.size(); ++i)
    {
        int val = pos_vec[i].second;
        if(m2.find(val) == m2.end())
        {
            m2[val] = 1;
        }
        else
        {
            m2[val]++;
        }
    } 

    map<int, int>::iterator m2_iter;
    for(m2_iter = m2.begin(); m2_iter != m2.end(); ++m2_iter)
    {
        //cout<<m1_iter->first<<" "<<m1_iter->second<<endl;
        res += m2_iter->second * (m2_iter->second - 1) / 2;
    }

    map<pair<int, int>, int> m3;   
    map<pair<int, int>, int> m4; 
    for(int i = 0; i < pos_vec.size(); ++i)
    {
        if(i == 0)
        {
            m3[pos_vec[i]] = 1;
            m4[pos_vec[i]] = 1;
        }
        else
        {
            pair<int, int> cur = pos_vec[i];
            
            bool flag_1 = false;
            map<pair<int, int>, int>::iterator m3_iter;
            for(m3_iter = m3.begin(); m3_iter != m3.end(); ++m3_iter)
            {
                pair<int, int> cmp = m3_iter->first;
                int cmp_x = cur.first - cmp.first;
                int cmp_y = cur.second - cmp.second;
                if(cmp_y == 0) continue;
                int cmp_res = cmp_x / cmp_y;
                int cmp_resudal = cmp_x % cmp_y;
                if((cmp_res == -1) && cmp_resudal == 0)
                {
                   m3[cmp] += 1; 
                   flag_1 = true;
                }
            }
            if(!flag_1) m3[cur] = 1;

            bool flag_2 = false;
            map<pair<int, int>, int>::iterator m4_iter;

            for(m4_iter = m4.begin(); m4_iter != m4.end(); ++m4_iter)
            {
                pair<int, int> cmp = m4_iter->first;
                int cmp_x = cur.first - cmp.first;
                int cmp_y = cur.second - cmp.second;
                if(cmp_y == 0) continue;
                int cmp_res = cmp_x / cmp_y;
                int cmp_resudal = cmp_x % cmp_y;
                if((cmp_res == 1) && cmp_resudal == 0)
                {
                   m4[cmp] += 1; 
                   flag_2 = true;
                }
            }
            if(!flag_2) m4[cur] = 1;
        }
    }

    map<pair<int, int>, int>::iterator m3_itr;
    for(m3_itr = m3.begin(); m3_itr != m3.end(); ++m3_itr)
    {
        //cout<<m3_itr->first.first<<" "<<m3_itr->first.second<<" "<<m3_itr->second<<endl;
        res += m3_itr->second * (m3_itr->second - 1) / 2;
    }

    /*map<pair<int, int>, int> m4;    
    for(int i = 0; i < pos_vec.size(); ++i)
    {
        if(i == 0)
        {
            m4[pos_vec[i]] = 1;
        }
        else
        {
            pair<int, int> cur = pos_vec[i];
            bool flag = false;
            map<pair<int, int>, int>::iterator m4_iter;
            for(m4_iter = m4.begin(); m4_iter != m4.end(); ++m4_iter)
            {
                pair<int, int> cmp = m4_iter->first;
                int cmp_x = cur.first - cmp.first;
                int cmp_y = cur.second - cmp.second;
                if(cmp_y == 0) continue;
                int cmp_res = cmp_x / cmp_y;
                int cmp_resudal = cmp_x % cmp_y;
                if((cmp_res == 1) && cmp_resudal == 0)
                {
                   m4[cmp] += 1; 
                   flag = true;
                }
            }
            if(!flag) m4[cur] = 1;
        }
    }*/

    map<pair<int, int>, int>::iterator m4_itr;
    for(m4_itr = m4.begin(); m4_itr != m4.end(); ++m4_itr)
    {
        //cout<<m4_itr->first.first<<" "<<m4_itr->first.second<<" "<<m4_itr->second<<endl;
        res += m4_itr->second * (m4_itr->second - 1) / 2;
    }


    cout<<res<<endl;

    return 0;
}