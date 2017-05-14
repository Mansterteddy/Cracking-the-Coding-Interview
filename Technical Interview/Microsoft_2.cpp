#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin>>N>>Q;

    int max_log_robots = log10(N) / log10(2) + 1;

    int max_count_robots = pow(2, max_log_robots);

    //cout<<"num: "<<max_count_robots<<endl;

    int max_time = N;

    vector<int> vec(max_count_robots);

    for(int i = 0; i < max_count_robots; ++i)
    {
        //cout<<"i: "<<i+1<<endl;

        int time_used = 0;
        int cur_num_robots = i + 1;
        int count_produce_robots = log10(cur_num_robots) / log10(2);
        time_used += count_produce_robots * Q;
        //cout<<"time used: "<<time_used<<endl;

        int waited_robots_num = cur_num_robots - pow(2, count_produce_robots);
        int residual_jobs = N;
        //cout<<"count robots: "<<count_produce_robots<<" waited: "<<waited_robots_num<<endl;
        if(waited_robots_num != 0)
        {
            int during_produce_jobs = (pow(2, count_produce_robots) - waited_robots_num) * Q;
            residual_jobs = N - during_produce_jobs;
            time_used += Q;
        }
        //cout<<"time used: "<<time_used<<endl;
        //cout<<"residual jobs: "<<residual_jobs<<endl;

        int dom = residual_jobs / cur_num_robots;
        int res = residual_jobs % cur_num_robots;
        if(res == 0) time_used += dom;
        else time_used += dom + 1;
        //cout<<"time used: "<<time_used<<endl;
        
        vec[i] = time_used;
    }

    int min = vec[0];
    for(int i = 1; i < vec.size(); ++i)
    {
        if(vec[i] < min) min = vec[i];
    }

    cout<<min<<endl;

    return 0;
}