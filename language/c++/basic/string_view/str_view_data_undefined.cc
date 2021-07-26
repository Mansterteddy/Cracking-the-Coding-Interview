#include <cstring>
#include <iostream>
#include <string_view>

int main(){
    std::string_view str{"balloon"};

    str.remove_prefix(1);
    str.remove_suffix(3);

    std::cout << str << " has " << std::strlen(str.data()) << " letter(s)\n";
    std::cout << "str.data() is " << str.data() << "\n";
    std::cout << "str is " << str << "\n";

    return 0;
}