#include <iostream>
#include <string>
#include <string_view>

void print(std::string s){
    std::cout << s << "\n";
}

int main(){
    std::string_view sv{"balloon"};
    sv.remove_suffix(3);

    std::string str{sv};
    print(str);
    print(static_cast<std::string>(sv));

    const char* szNullTerminated{ str.c_str()};
    std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";
    return 0;
}