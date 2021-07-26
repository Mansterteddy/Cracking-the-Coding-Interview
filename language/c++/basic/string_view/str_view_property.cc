#include <iostream>
#include <string_view>

int main(){
    std::string_view str{"Trains are fast!"};

    std::cout << str.length() << "\n";
    std::cout << str.substr(0, str.find(' ')) << "\n";
    std::cout << (str == "Trains are fast!") << "\n";

    std::cout << str.starts_with("Boats") << "\n";
    std::cout << str.ends_with("fast!") << "\n";

    std::cout << str << "\n";

    return 0;
}