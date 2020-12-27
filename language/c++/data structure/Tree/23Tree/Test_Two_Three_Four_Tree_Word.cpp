/** Program to the Two_Three_Four Tree Class */

#include <string>
#include <iostream>
#include <fstream>
#include "Two_Three_Four_Tree.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  Two_Three_Four_Tree<string> the_tree;
  string word;
  while (cin >> word) {
    the_tree.insert(word);
    cout << the_tree.to_string() << endl;
  }
}


  
