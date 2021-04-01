#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{
    int start, end;
};

bool compareInterval(Interval i1, Interval i2){
    return (i1.start < i2.start);
}

int main(){

    Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, compareInterval);

    cout << "sorted array: ";
    for(int i = 0; i < n; i++){
        cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
    }

    return 0;
}