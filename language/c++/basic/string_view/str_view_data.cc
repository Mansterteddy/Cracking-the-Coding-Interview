#include <cstring>
#include <iostream>
#include <string_view>

int main(){
    std::string_view str{"balloon"};
    std::cout << str << "\n";

    std::cout << std::strlen(str.data()) << "\n";
    return 0;
}