/** Program to the Two_Three Tree Class */

#include <string>
#include <iostream>
#include <fstream>
#include "B_Tree.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  B_Tree<double, NN> the_tree;
  double x;
  while (cin >> x) {
    the_tree.insert(x);
    cout << the_tree.to_string() << endl;
  }
  //  while (cin >> x) {
  //  the_tree.erase(x);
  //  cout << the_tree.to_string() << endl;
  // }
}


  
