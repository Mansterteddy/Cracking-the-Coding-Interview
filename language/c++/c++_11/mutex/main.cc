#include <thread>
#include <iostream>

using namespace std;

int g_count = 0;

int print(int n, char c){
    for(int i = 0; i < n; ++i){
        std::cout << c;
        g_count++;
    }
    cout << "\n";
    cout << "count=" << g_count << endl;
    return 0;
}

int main(){
    thread t1(print, 10, 'A');
    thread t2(print, 5, 'B');
    t1.join();
    t2.join();

    return 0;
}