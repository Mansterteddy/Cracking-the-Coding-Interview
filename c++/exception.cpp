#include <iostream>

using namespace std;

class NumberParseException {};

bool isNumber(char * str) {
     if (str == NULL) 
        return false;
     int len = strlen(str);
     if (len == 0) 
        return false;
     bool isaNumber = false;
     char ch;
     for (int i = 0; i < len; i++) {
         if (i == 0 && (str[i] == '-' || str[i] == '+')) 
            continue;
         if (isdigit(str[i])) {
            isaNumber = true;
         } else {
           isaNumber = false;
           break;
         }
     }
     return isaNumber;
}

int parseNumber(char * str){
    if (!isNumber(str)) 
       throw NumberParseException();
    return atoi(str);
}


int main()
{
    char *str1 = "1", *str2 = NULL;
    try {
        int num1 = parseNumber(str1);
        int num2 = parseNumber(str2);
        printf("sum is %d\n", num1 + num2);
    } catch (NumberParseException) {
        cout<<"Input is not integer!"<<endl;
    }

}