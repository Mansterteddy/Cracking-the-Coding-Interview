//给定一个点集，构造这个点集中所有直线的hash table，并返回hash value最大的那条直线

#include <iostream>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct point{
    double x, y;
};

class line{
    public:
        double epsilon, slope, intercept;
        bool bslope;

    public:
        line(){};
        line(point p, point q){
            epsilon = 0.00001;
            if(abs(p.x - q.x) > epsilon){
                slope = (p.y - q.y) / (p.x - q.x);
                intercept = p.y - slope * p.x;
                bslope = true;
            }
            else{
                bslope = false;
                intercept = p.x;
            }
        }
        int hashcode(){
            int s1 = (int)(slope * 1000);
            int in = (int)(intercept * 1000);
            return s1 * 1000 + in;
        }

        void print(){
            cout<<"y = "<<slope<<"x + "<<intercept<<endl;
        }
};

line find_best_line(point *p, int point_num){
    line bestline;
    bool first = true;
    map<int, int> mii;
    for(int i = 0; i < point_num; i++){
        for(int j = i + 1; j < point_num; j++){
            line l(p[i], p[j]);
            if(mii.find(l.hashcode()) == mii.end()){
                mii[l.hashcode()] = 0;
            }
            mii[l.hashcode()] = mii[l.hashcode()] + 1;
            if(first){
                bestline = l;
                first = false;
            }
            else{
                if(mii[l.hashcode()] > mii[bestline.hashcode()])
                    bestline = l;
            }
        }
    }
    return bestline;
}

int main(){
    srand((unsigned)time(0));
    int graph_size = 100;
    int point_num = 500;
    point *p = new point[point_num];
    for(int i = 0; i < point_num; i++){
        p[i].x = rand() / double(RAND_MAX) * graph_size;
        p[i].y = rand() / double(RAND_MAX) * graph_size;
    }

    line l = find_best_line(p, point_num);
    l.print();
    return 0;
}