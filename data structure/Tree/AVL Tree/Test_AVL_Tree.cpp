#include <string>
#include <iostream>
#include <fstream>
#include "AVL_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main(int argc, char* argv[]) 
{

  AVL_Tree<double>* the_tree = NULL;
  the_tree = new AVL_Tree<double>;

  if (the_tree == NULL) 
  {
    cerr << "Did not specify a BST that is recognized\n";
    cerr << "Valid tree types: Binary_Search_Tree, AVL_Tree, "
	 << "or Red_Black_Tree\n";
    return 1;
  }

  double value;

  cout<<"Insert: 0, Erase: 1"<<endl;

  while(cin >> value)
  {
    if(value == 0.0)
    {
      cin >> value;
      cout<<"Insert value: "<<value<<endl;
      the_tree->insert(value);
    }
    else if(value == 1.0)
    {
      cin >> value;
      cout<<"Erase value: "<<value<<endl;
      the_tree->erase(value);
    }
    else
    {
      cout<<"No value: "<<value<<endl;
    }

    pre_order_traversal(*the_tree, cout, 0);

    cout<<"Insert: 0, Erase: 1"<<endl;
  }

/*
  while (cin >> value) 
  {
    if (value == 0.0) break;
    cout<<"value: "<<value<<endl;
    the_tree->insert(value);
    pre_order_traversal(*the_tree, cout, 0);
  }
  cin.clear();*/

/*
  while(cin >> value)
  {
    if(value = 0.0) break;
    cout<<"value: "<<value<<endl;
    the_tree->erase(value);
    pre_order_traversal(*the_tree, cout, 0);
  }
  cin.clear();*/

  return 0;
}


  
