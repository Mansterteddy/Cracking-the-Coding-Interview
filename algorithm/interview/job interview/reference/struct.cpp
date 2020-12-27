#include <iostream>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int main()
{
    Interval a;
    cout<<"x: "<<a.start<<" y: "<<a.end<<endl;

    Interval b(3, 4);
    cout<<"x: "<<b.start<<" y: "<<b.end<<endl;

    return 0;
}