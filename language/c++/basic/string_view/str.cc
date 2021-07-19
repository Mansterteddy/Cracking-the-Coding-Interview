#include <string>
#include <iostream>

int main(){
    char text[]{"hello"};

    std::string str{text};
    std::string more{str};

    std::cout << text << " " << str << " " << more << "\n";

    return 0;

}