#include <mutex>
#include <thread>
#include <iostream>

std::mutex g_mutex;
int g_count = 0;

int print(int n, char c){
    g_mutex.lock();
    for(int i = 0; i < n; ++i){
        std::cout << c;
        g_count++;
    }

    std::cout << "\n";
    std::cout << "count=" << g_count << std::endl;
    g_mutex.unlock();
    return 0;
}

int main(){
    std::thread t1(print, 10, 'A');
    std::thread t2(print, 5, 'B');
    t1.join();
    t2.join();

    return 0;
}