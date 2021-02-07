#include <iostream>
#include <array>
#include <algorithm>

int main(){

    std::array<int, 4> arr = {1, 2, 4, 3};

    std::sort(arr.begin(), arr.end());

    for(auto item: arr)
        std::cout << item << " ";


    return 0;
}