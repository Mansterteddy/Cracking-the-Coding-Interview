#include <iostream>
#include <string_view>

int main(){
    char arr[]{"Gold"};
    std::string_view str{arr};
    std::cout << str << "\n";
    arr[3] = 'f';
    std::cout << str << "\n";
    return 0;
}