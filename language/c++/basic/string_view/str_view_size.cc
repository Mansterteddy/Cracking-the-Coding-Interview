#include <iostream>
#include <iterator>
#include <string_view>

int main(){
    char vowels[]{'a', 'e', 'i', 'o', 'u'};
    std::string_view str{vowels, std::size(vowels)};
    std::cout << str << std::endl;
    return 0;
}