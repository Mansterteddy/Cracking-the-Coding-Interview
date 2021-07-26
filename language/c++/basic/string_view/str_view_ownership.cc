#include <iostream>
#include <string>
#include <string_view>

std::string_view askForName(){
    std::cout << "What's your name?\n";

    std::string str{};
    std::cin >> str;

    std::string_view view{str};
    std::cout << "Hello " << view << "\n";
    return view;
}

int main(){
    std::string_view view{ askForName()};
    std::cout << "Your name is " << view << "\n";
    return 0;
}