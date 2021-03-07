#include <iostream>

using namespace std;

void func(void);

static int cur_count = 10;

int main(){
    while(cur_count--){
        func();
    }
    return 0;
}

void func(void){
    static int i = 5;
    i++;
    cout << i << " " << cur_count << endl;
}