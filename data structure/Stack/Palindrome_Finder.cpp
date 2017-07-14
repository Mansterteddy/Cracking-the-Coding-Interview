/** Class with functions to check whether a string is a palindrome. */

#include "Palindrome_Finder.h"
#include <cctype>
#include <algorithm> 
using namespace std;

/** Function to fill a stack of characters from an input string. */
void Palindrome_Finder::fill_stack() {
  for (size_t i = 0; i < input_string.size(); i++) {
    char_stack.push(input_string[i]);
  }
}

/** Function to build a string containing the characters in a stack.
    post: The stack is empty.
    @return The string containing the words in the stack
*/
string Palindrome_Finder::build_reverse() {
  string result;
  while (!char_stack.empty()) {
    // Remove top item from stack and append it to result.
    result += char_stack.top();
    char_stack.pop();
  }
  return result;
}

/** Function class to perform case-insensitive comparison
    of characters. */
class Ci_Equal {
  public:
    bool operator()(char c1, char c2) {
      return toupper(c1) == toupper(c2);
    }
};


bool Palindrome_Finder::is_palindrome() {
  string reverse = build_reverse();
  return equal(input_string.begin(), input_string.end(),
               reverse.begin(), Ci_Equal());
}

