#include <algorithm>
#include <iostream>

using namespace std;

bool order(int a, int b){
    return (a < b);
}

int main(){

    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, greater<int>());

    cout << "sorted array: ";
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + n, order);
    cout << "sorted array: ";
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    return 0;

}