/** Program to test binary tree class */

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Tree.h"
#include "pre_order_traversal.h"
#include "post_order_traversal.h"
#include "in_order_traversal.h"

using namespace std;

int main(int argc, char* argv[]) 
{

  if (argc < 2) 
  {
    cerr << "Usage Test_Binary_Tree <input file>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) 
  {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }

  Binary_Tree<string> the_tree;
  in >> the_tree;
  cout << "Pre-order traversal\n";
  pre_order_traversal(the_tree, cout, 0);
  //  cout << the_tree.pre_order() << endl;
  cout << "Post-order traversal\n";
  post_order_traversal(the_tree, cout, 0);
  //  cout << the_tree.post_order() << endl;
  cout << "In-order traversal\n";
  in_order_traversal(the_tree, cout, 0);
  //  cout << the_tree.in_order() << endl;
  cout << "String representation\n";
  cout << the_tree << endl;
  //  cout << "The height of the tree is " << the_tree.height() << endl;
  //  cout << "The tree has " << the_tree.number_of_nodes() << " nodes\n";
  return 0;
}

  
