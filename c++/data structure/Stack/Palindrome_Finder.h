#ifndef PALINDROME_FINDER_H_
#define PALINDROME_FINDER_H

#include <string>
#include <stack>

/** Class with functions to check whether a string is a palindrome. */
class Palindrome_Finder {

  public:
    /** Store the argument string in a stack of characters.
        @param str String of characters to store in the stack
    */
    Palindrome_Finder(const std::string& str): input_string(str) {
      fill_stack();
    }
   
    /** Function to determine whether input string is a palidrome. */
    bool is_palindrome();
    
  private:
    /** Function to fill a stack of characters from an input string. */
    void fill_stack();
  
    /** Function to build a string containing the characters in a stack.
        post: The stack is empty.
        @return The string containing the words in the stack
    */
    std::string build_reverse();

    /** String to store in stack. */
    std::string input_string;
  
    /** Stack to hold characters. */
    std::stack<char> char_stack;

};

#endif
