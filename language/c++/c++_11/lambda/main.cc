#include <cmath>
#include <algorithm>
#include <iostream>

void abssort(float* x, unsigned n){
    std::sort(x, x + n, 
    [](float a, float b){
        return (std::abs(a) < std::abs(b));
    }
    );
}

int main(){
    float x[] = {1.0, 3.1, 2.4, 7.0, 6.7};
    abssort(x, 4);

    for(int i = 0; i < 5; ++i){
        std::cout << x[i] << " ";
    }

    return 0;

}