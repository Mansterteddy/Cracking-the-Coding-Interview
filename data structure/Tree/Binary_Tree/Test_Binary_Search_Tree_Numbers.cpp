/** Program to test binary tree class using numbers*/

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main() 
{
  Binary_Search_Tree<double> the_tree;
  double value;
  while (cin >> value) {
    if (value == 0) break;
    the_tree.insert(value);
    pre_order_traversal(the_tree, cout, 0);
  }
  cin.clear();
  while (cin >> value) {
    if (value == 0) break;
    the_tree.erase(value);
    pre_order_traversal(the_tree, cout, 0);
  }
}


  
