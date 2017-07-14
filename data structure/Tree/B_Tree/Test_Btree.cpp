/** Program to the Two_Three Tree Class */

#include <string>
#include <iostream>
#include <fstream>
#include "B_Tree.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  B_Tree<string, NN> the_tree;
  string word;
  while (cin >> word) {
    the_tree.insert(word);
    cout << the_tree.to_string() << endl;
  }
}


  
