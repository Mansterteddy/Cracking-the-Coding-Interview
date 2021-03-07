#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

std::mutex m;
std::condition_variable cond_var;
bool ready = false;

void print_id(int id){
    std::unique_lock<std::mutex> lock(m);
    while(!ready){
        cond_var.wait(lock);
    }

    std::cout << "thread " << id << "\n";
}

void go(){
    std::unique_lock<std::mutex> lock(m);
    ready = true;
    cond_var.notify_all();
}

int main(){
    std::thread threads[5];
    for(int i = 0; i < 5; ++i){
        threads[i] = std::thread(print_id, i);
    }

    std::cout << "5 threads ready to race...\n";
    go();

    for(auto& th : threads){
        th.join();
    }

    return 0;
}
