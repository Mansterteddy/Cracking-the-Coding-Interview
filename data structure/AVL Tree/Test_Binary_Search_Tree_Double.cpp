/** Program to test binary tree class */

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  if (argc < 2) 
  {
    cerr << "Usage: " << argv[0] << " <tree type>\n";
    cerr << "Valid tree types: Binary_Search_Tree, AVL_Tree, "
	 << "or Red_Black_Tree\n";
    return 1;
  }

  Binary_Search_Tree<double>* the_tree = NULL;
  the_tree = new Binary_Search_Tree<double>;

/*  if (string(argv[1]) == "Binary_Search_Tree") 
    the_tree = new Binary_Search_Tree<double>;
  else if (string(argv[1]) == "AVL_Tree")
    the_tree = new AVL_Tree<double>; 
  else if (string(argv[1]) == "Red_Black_Tree")
    the_tree = new Red_Black_Tree<double>;*/
  if (the_tree == NULL) 
  {
    cerr << "Did not specify a BST that is recognized\n";
    cerr << "Valid tree types: Binary_Search_Tree, AVL_Tree, "
	 << "or Red_Black_Tree\n";
    return 1;
  }

  double value;
  while (cin >> value) 
  {
    if (value == 0.0) break;
    the_tree->insert(value);
    pre_order_traversal(*the_tree, cout, 0);
  }
  cin.clear();
  //  while (cin >> value) {
  //  if (value == 0.0) break;
  //  the_tree->erase(value);
  //  pre_order_traversal(*the_tree, cout, 0);
  // }

  return 0;
}


  
