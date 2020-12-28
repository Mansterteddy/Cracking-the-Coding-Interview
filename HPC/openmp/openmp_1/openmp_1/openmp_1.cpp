// openmp_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <omp.h>
#include <iostream>

int main()
{
    std::cout << "Starting Program\n";

    int nThreads, tid;

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        std::cout << "Running on thread: " << tid << std::endl;
    
        if (tid == 0) {
            nThreads = omp_get_num_threads();
            std::cout << "Total number of threads: " << nThreads << std::endl;
        }
    }

    std::cout << "Finished!" << std::endl;

    return 0;
}