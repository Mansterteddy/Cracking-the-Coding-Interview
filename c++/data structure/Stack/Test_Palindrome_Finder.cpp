/** Program to test Palindrome_Finder */

#include "Palindrome_Finder.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

  string line;
  cout << "Enter a string followed by a new line\n"
       << "To quit, enter an empty line:  ";
  while (getline(cin, line) && (line != "")) {
    cout << line << endl;
    if (Palindrome_Finder(line).is_palindrome()) {
      cout << "Is a palindrome\n\n";
    } else {
      cout << "Is not a palindrome\n\n";
    }
    cout << "Enter a string: ";
  }
}
