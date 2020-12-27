/** Program to test binary tree class using words*/

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main() 
{
  Binary_Search_Tree<string> the_tree;
  string word;
  while (cin >> word) {
    the_tree.insert(word);
    pre_order_traversal(the_tree, cout, 0);
  }
  cin.clear();
  while (cin >> word) {
    the_tree.erase(word);
    pre_order_traversal(the_tree, cout, 0);
  }
}


  
