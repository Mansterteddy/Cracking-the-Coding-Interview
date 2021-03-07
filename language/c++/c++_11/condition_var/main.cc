#include <mutex>
#include <thread>
#include <string>
#include <iostream>
#include <condition_variable>

std::mutex m;
std::condition_variable cond_var;

void worker_thread(){
    std::unique_lock<std::mutex> lock(m);
    std::cout << "worker_thread() wait\n";
    cond_var.wait(lock);

    std::cout << "worker_thread is processing data\n";
}

int main(){
    std::thread worker(worker_thread);

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "main() notify_one\n";
    cond_var.notify_one();

    worker.join();
    std::cout << "main() end\n";
    return 0;
}