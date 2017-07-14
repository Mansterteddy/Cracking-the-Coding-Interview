/** Program to the Two_Three Tree Class */

#include <string>
#include <iostream>
#include <fstream>
#include "Two_Three_Four_Tree.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  Two_Three_Four_Tree<double> the_tree;
  double value;
  while (cin >> value) {
    if (value == 0.0) break;
    the_tree.insert(value);
    cout << the_tree.to_string() << endl;
  }
}


  
